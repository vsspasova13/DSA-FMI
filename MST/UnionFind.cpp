#include "UnionFind.h"

size_t UnionFind::getParent(size_t vertex)
{
    if (parentsContainer[vertex] == vertex)
    {
        return vertex;
    }

    return parentsContainer[vertex] = getParent(parentsContainer[vertex]);
}

UnionFind::UnionFind(size_t vertices) : parentsContainer(vertices), sizes(vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        parentsContainer[i] = i;
        sizes[i] = 1;
    }
}

bool UnionFind::areInOneSet(size_t first, size_t second)
{
    return getParent(first) == getParent(second);
}

void UnionFind::unionVertices(size_t first, size_t second)
{
    size_t parent1 = getParent(first);
    size_t parent2 = getParent(second);

    if (parent1 == parent2) return;

    if (sizes[parent1] < sizes[parent2])
    {
        std::swap(parent1, parent2);
    }

    parentsContainer[parent2] = parent1;
    sizes[parent1] += sizes[parent2];
}
