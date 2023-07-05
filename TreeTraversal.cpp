#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Vertex
{
    vector<int> list;
    bool visited;
};

void BreadthFirstSearch(int k, vector<string> people, vector<int> levels)
{
    int n = k;
    int temp;
    int parent;
    queue<int> queueVertices;
    queue<int> queueParents;
    queueVertices.push(n);
    queueParents.push(n);
    v[n].visited = true;
    while (!queueVertices.empty())
    {
        n = queueVertices.front();
        temp = queueParents.front();

        for (int j = 0; j < levels[n]; j++)
        {
            cout << "\t";
        }
        cout << people[n] << endl;

        queueVertices.pop();

        for (int i = 0; i < v[n].list.size(); i++)
        {
            if (!v[v[n].list[i]].visited)
            {
                queueVertices.push(v[n].list[i]);
                v[v[n].list[i]].visited = true;
                queueParents.push(v[n].list[i]);
                levels[v[n].list[i]] = levels[temp] + 1;
            }
        }
        queueParents.pop();
    }
}

void DepthFirstSearch(int k, vector<string> people, int level)
{
    for (int j = 0; j < level; j++)
    {
        cout << "    ";
    }
    cout << people[k] << endl;
    v[k].visited = true;
    for (int i = 0; i < v[k].list.size(); i++)
    {
        if (!v[v[k].list[i]].visited)
        {
            DepthFirstSearch(v[k].list[i], people, level + 1);
        }
    }
}

int main()
{
    vector<vector<int>> neighbors = {{1, 3, 9}, {2, 4}, {}, {5, 6}, {}, {8}, {7}, {}, {}, {10, 11, 12}, {}, {}, {}};
    vector<string> people = {"Jan Kowalski", "Roman Jozwierz", "Fryderyk Helc", "Zuzanna Nowak", "Robert Zielony", "Joanna Braz", "Jan Szary", "Jadwiga Niebieska", "Henryk Borny", "Kazimierz Czarny", "Kamil Dlugi", "Franciszek Slaby", "Dorota Prewal"};
    int n = 13;
    vector<Vertex> vertices(n);

    for (int i = 0; i < n; i++)
    {
        vertices[i].visited = false;
        vertices[i].list = neighbors[i];
    }

    vector<int> levels(n, 0);

    cout << "\n--------------------BREADTH-FIRST SEARCH--------------------\n\n";
    BreadthFirstSearch(0, people, levels);

    cout << "\n\n";

    for (int i = 0; i < n; i++)
    {
        vertices[i].visited = false;
    }

    cout << "--------------------DEPTH-FIRST SEARCH--------------------\n\n";
    DepthFirstSearch(0, people, 0);

    cout << "\n---------------------------------------------------------\n\n";

    return 0;
}