// Simulate genetic inheritance of blood type
// NOTE: don't check out until you run check50 on this problem!!

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Seed random number generator
    srand(time(0));

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    // TODO: Allocate memory for new person
    person* fam = malloc(sizeof(person)); //https://www.geeksforgeeks.org/calloc-versus-malloc/

    // Generation with parent data
    if (generations > 1)
    {
        // TODO: Recursively create blood type histories for parents
        (*fam).parents[1] = create_family(generations-1);
        (*fam).parents[0] = create_family(generations-1);

        // TODO: Randomly assign child alleles based on parents
        (*fam).alleles[0] = (*(*fam).parents).alleles[rand() % 1];
        (*fam).alleles[1] = (*(*fam).parents + 1).alleles[rand() % 1];


    }

    // Generation without parent data
    else
    {
        // TODO: Set parent pointers to NULL
        (*fam).parents[1] = NULL;
        (*fam).parents[0] = NULL;

        // TODO: Randomly assign alleles
        (*fam).alleles[1] = random_allele();
        (*fam).alleles[0] = random_allele();
    }

    // TODO: Return newly created person
    return fam;
}

// Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    // TODO: Handle base case

    // TODO: Free parents

    // TODO: Free child
}

// Print each family member and their alleles.
void print_family(person *p, int generation)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print person
    printf("Generation %i, blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Randomly chooses a blood type allele.
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}