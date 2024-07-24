//		Klasse "Digraph" Deklarationen
#ifndef DIGRAPH_H
#define DIGRAPH_H
#include <iostream>
#include <iomanip>
#include <string>
#include <cfloat>  // wg. MAXFLOAT
using namespace std;

const double noEdge = FLT_MAX;
const double weightBackEdge = -1.0;
const double weightCrossEdge = -2.0;
const double weightForwardEdge = -3.0;

enum color_node {
    WHITE = 0, GREY = 1, BLACK = 2
};

template <class TV, int maxNodes>
class Digraph {
private:

    class Vertex {
    public:
        Vertex() { // Konstruktor
            indegree = outdegree = ord = 0;
            living = false;
            color = WHITE;
            start = end = 0;
            predecessor = -1;
        }
        TV value; // Daten des Knotens
        int indegree; // Eingangsgrad
        int outdegree; // Ausgangsgrad
        int ord; // Ordnungszahl des Knotens
        bool living; // Knoten existiert
        color_node color; //Farbcodierung für Bearbeitungszustand
        int start, end; //Start und Ende der Bearbeitungszeit für DFS
        int predecessor; //Für aufspannenden Baum
    };
    int numVertices; // Anzahl der Knoten eines Digraphen
    int numEdges; // Anzahl der Kanten eines Digraphen
    Vertex vertices[maxNodes]; // repraesentiert Knoten des Digraphen
    double edges[maxNodes][maxNodes]; // repraesentiert bewertete Kanten des Graphen
public:// Operationen auf dem Graphen
    Digraph(); // Graphen generieren
    ~Digraph(); // Graphen freigeben
    void insertVertex(int n, TV m); // fuegt neuen Knoten n mit Markierung m ein
    void deleteVertex(int n); // entfernt Knoten n
    TV getVertexValue(int n); // gibt Wert des Knoten n zurueck
    void setVertexValue(int n, TV m); // Aendert Wert des Knoten n
    int firstVertex(); // Erster Knoten des Graphen
    int nextVertex(int n); // nächster Knoten nach n (-1 wenn keiner existiert)
    void insertEdge(int v, int w, double weight); // fgt neue Kante (v,w) mit Gewicht weight ein
    void insertEdge(int v, int w); // fgt neue Kante (v,w) mit Gewicht 0 ein
    void deleteEdge(int v, int w); // loescht Kante (v,w)
    int firstEdge(int v); // Erster Kante des Knoten v des Graphen
    int nextEdge(int v, int n); // naechste Kante des Knotens v nach n
    // (-1 wenn keiner existiert)
    bool isVisited(int n); // true, wenn Knoten n besucht, sonst false
    void setEdgeWeight(int v, int w, double weight); //aendert Kantengewicht
    bool isEdge(int v, int w); // existiert Kante (v,w)?
    double getEdge(int v, int w); // gibt Kantenbewertung  von (v,w) zurck
    int getNumVertices(); // Anzahl der Knoten
    int getMaxVertices(); // Max. Anzahl der Knoten
    int getNumEdges(); // Anzahl der Kanten
    int getIndegree(int n); // liefert Eingangsgrad eines Knotens
    int getOutdegree(int n); // liefert Ausgangsgrad eines Knotens
    int getColor(int n); //liefert Farbe des Knotens
    void setColor(int n, color_node color); // Knoten n als nicht besucht, besucht oder abgeschlossen markieren
    int getStart(int n); //liefert Startzeitpunkt
    void setStart(int n, int time); //Startzeitpunkt der Bearbeitung für DFS setzen
    int getEnd(int n); //liefert Endzeitpunkt
    void setEnd(int n, int time); //Endzeitpunkt der Bearbeitung für DFS setzen
    int getOrd(int v); // Ordnungsnummer des Knotens v liefern
    int getPredecessor(int n); //liefert Vorgaengerknoten
    void setPredecessor(int n, int pre); //Vorgängerknoten setzen
    void printVertex(int n); // Ausgabe des Knotens n eines Graphen
    void printVertices(); // Ausgabe aller Knotens  eines Graphen
    void printAdjMatrix(); // Adjazenzmatrix ausgeben
    void deleteDigraph(); // alle Knoten und Kanten loeschen
};

template <class TV, int maxVertices>
Digraph<TV, maxVertices>::Digraph() {
    numVertices = numEdges = 0;
    for (int i = 0; i < maxVertices; i++)
        for (int j = 0; j < maxVertices; j++)
            edges[i][j] = noEdge;
}

template <class TV, int maxVertices>
Digraph<TV, maxVertices>::~Digraph() {
    ;
}

template <class TV, int maxVertices>
void Digraph<TV, maxVertices>::insertVertex(int n, TV m) {
    if (n >= 0 && n < maxVertices) {
        vertices[n].living = true;
        vertices[n].value = m;
    }
}

template <class TV, int maxVertices>
int Digraph<TV, maxVertices>::firstVertex() {
    for (int i = 0; i < maxVertices; i++)
        if (vertices[i].living == true)
            return i;
    return -1;
}

template <class TV, int maxVertices>
int Digraph<TV, maxVertices>::nextVertex(int n) { // nächster Knoten nach n (-1 wenn n der letzte ist)
    if (n < 0 || n > maxVertices - 2) return -1;
    for (int i = n + 1; i < maxVertices; i++)
        if (vertices[i].living == true)
            return i;
    return -1;
}

template <class TV, int maxVertices>
int Digraph<TV, maxVertices>::firstEdge(int v) {
    if (vertices[v].living == true)
        for (int i = 0; i < maxVertices; i++)
            if (isEdge(v, i))
                return i;
    return -1;
}

template <class TV, int maxVertices>
int Digraph<TV, maxVertices>::nextEdge(int v, int n) {
    if (vertices[v].living == true)
        for (int i = n + 1; i < maxVertices; i++)
            if (isEdge(v, i))
                return i;
    return -1;
}

template <class TV, int maxVertices>
void Digraph<TV, maxVertices>::deleteVertex(int n) {
    if (n >= 0 && n < maxVertices) {
        vertices[n].living = false;
        vertices[n].color = WHITE;
        vertices[n].value = vertices[n].ord = vertices[n].start =
            vertices[n].end = vertices[n].indegree =
            vertices[n].outdegree = vertices[n].predecessor = 0;
    }
    for (int i = 0; i < maxVertices; i++) {
        //  Vorhandene Kanten zum Knoten löschen
        edges[i][n] = noEdge;
        edges[n][i] = noEdge;
    }
}

template <class TV, int maxVertices>
TV Digraph<TV, maxVertices>::getVertexValue(int n) {
    if (n >= 0 && n < maxVertices && vertices[n].living) {
        return vertices[n].value;
    }
}

template <class TV, int maxVertices>
int Digraph<TV, maxVertices>::getOrd(int n) {
    if (n >= 0 && n < maxVertices && vertices[n].living) {
        return vertices[n].ord;
    }
    return -1;
}

template <class TV, int maxVertices>
int Digraph<TV, maxVertices>::getPredecessor(int n) {
    return vertices[n].predecessor;
}

template <class TV, int maxVertices>
void Digraph<TV, maxVertices>::setPredecessor(int n, int pre) {
    vertices[n].predecessor = pre;
}

template <class TV, int maxVertices>
void Digraph<TV, maxVertices>::setVertexValue(int n, TV m) {
    if (n >= 0 && n < maxVertices && vertices[n].living) {
        vertices[n].value = m;
    }
}

template <class TV, int maxVertices>
int Digraph<TV, maxVertices>::getMaxVertices() {
    return maxVertices;
}

template <class TV, int maxVertices>
int Digraph<TV, maxVertices>::getColor(int n) {
    return vertices[n].color;
}

template <class TV, int maxVertices>
void Digraph<TV, maxVertices>::setColor(int n, color_node color) {
    if (n >= 0 && n < maxVertices && vertices[n].living)
        vertices[n].color = color;
}

template <class TV, int maxVertices>
int Digraph<TV, maxVertices>::getStart(int n) {
    return vertices[n].start;
}

template <class TV, int maxVertices>
void Digraph<TV, maxVertices>::setStart(int n, int time) {
    if (n >= 0 && n < maxVertices && vertices[n].living)
        vertices[n].start = time;
}

template <class TV, int maxVertices>
int Digraph<TV, maxVertices>::getEnd(int n) {
    return vertices[n].end;
}

template <class TV, int maxVertices>
void Digraph<TV, maxVertices>::setEnd(int n, int time) {
    if (n >= 0 && n < maxVertices && vertices[n].living)
        vertices[n].end = time;
}

template <class TV, int maxVertices>
bool Digraph<TV, maxVertices>::isVisited(int n) {
    if (n >= 0 && n < maxVertices && vertices[n].living) {
        return vertices[n].color;
    }
    return false;
}

template <class TV, int maxVertices>
void Digraph<TV, maxVertices>::insertEdge(int v, int w, double weight) {
    if (v >= 0 && v < maxVertices && w >= 0 && w < maxVertices && vertices[v].living && vertices[w].living && weight >= 0) {
        edges[v][w] = weight;
        vertices[v].outdegree++;
        vertices[v].ord++;
        vertices[w].indegree++;
        vertices[w].ord++;
    }
}

template <class TV, int maxNodes>
void Digraph<TV, maxNodes>::insertEdge(int v, int w) {
    insertEdge(v, w, 0);
}

template <class TV, int maxNodes>
void Digraph<TV, maxNodes>::deleteEdge(int v, int w) {
    if (v >= 0 && v < maxNodes && w >= 0 && w < maxNodes && vertices[v].living && vertices[w].living) {
        edges[v][w] = noEdge;
        vertices[v].outdegree--;
        vertices[v].ord--;
        vertices[w].indegree--;
        vertices[w].ord--;
    }
}

template <class TV, int maxNodes>
void Digraph<TV, maxNodes>::setEdgeWeight(int v, int w, double weight) {
    edges[v][w] = weight;
}

template <class TV, int maxNodes>
bool Digraph<TV, maxNodes>::isEdge(int v, int w) {
    if (v >= 0 && v < maxNodes && w >= 0 && w < maxNodes)
        return edges[v][w] != noEdge;
    return false;
}

template <class TV, int maxNodes>
double Digraph<TV, maxNodes>::getEdge(int v, int w) {
    if (isEdge(v, w))
        return edges[v][w];
    return noEdge;
}

template <class TV, int maxNodes>
int Digraph<TV, maxNodes>::getNumEdges() {
    return numEdges;
}

template <class TV, int maxNodes>
int Digraph<TV, maxNodes>::getNumVertices() {
    return numVertices;
}

template <class TV, int maxNodes>
int Digraph<TV, maxNodes>::getIndegree(int n) {
    return vertices[n].indegree;
}

template <class TV, int maxNodes>
int Digraph<TV, maxNodes>::getOutdegree(int n) {
    return vertices[n].outdegree;
}

template <class TV, int maxNodes>
void Digraph<TV, maxNodes>::printVertices() {
    cout << "Knoten:" << endl;
    for (int i = 0; i < maxNodes; i++) {
        printVertex(i);
    }
}

template <class TV, int maxNodes>
void Digraph<TV, maxNodes>::printVertex(int n) {
    string color;
    if (vertices[n].living) {
        if (getColor(n) == 0)
            color = "WHITE";
        else if (getColor(n) == 1)
            color = "GREY";
        else
            color = "BLACK";
        cout << "Nummer: " << n << " Wert: " << getVertexValue(n) << " Ordnung: " << getOrd(n)
             << " Farbe: " << setw(6) << color << " Start: " << getStart(n) << " Ende: " << getEnd(n)
             << " Vorgaenger: " << getPredecessor(n) << endl;
    }
}

template <class TV, int maxNodes>
void Digraph<TV, maxNodes>::printAdjMatrix() {
    cout << "Adjazenz Matrix:" << endl;
    cout << "    ";
    for (int i = 1; i < maxNodes; i++)
        cout << setw(5) << i << " ";
    cout << "\n  --";
    for (int i = 1; i < maxNodes; i++)
        cout << "------";
    cout << endl;
    for (int i = 1; i < maxNodes; i++) {
        cout << "  " << i << "|";
        for (int j = 1; j < maxNodes; j++) {
            if (isEdge(i, j))
                cout << setw(5) << getEdge(i, j) << " ";
            else
                cout << setw(5) << "-" << " ";
        }
        cout << endl;
    }
}

template <class TV, int maxNodes>
void Digraph<TV, maxNodes>::deleteDigraph() {
    for (int i = 0; i < maxNodes; i++)
        deleteVertex(i);
    for (int i = 0; i < maxNodes; i++)
        for (int j = 0; j < maxNodes; j++)
            deleteEdge(i, j);
}
#endif
