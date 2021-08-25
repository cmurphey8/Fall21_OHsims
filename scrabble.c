#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2) {
        printf("player 1 wins\n");
        return 0;
    }
    printf("player 2 wins\n");
}

// TODO: Compute and return score for string
int compute_score(string word)
{
    // declare sum in scope to return
    int sum;

    // init sum to 0 && loop through all char indexes of this word
    for (int char = 0, sum = 0; char < (sizeof(*word) / sizeof(*(word + char))); char++){

        // map word via ascii to range 0-25: subtract off a = 97
        sum += POINTS[word[char] - 'a'];
    }

    // return sum
    return sum;
}
