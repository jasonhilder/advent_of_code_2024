#include <cstdlib>
#include <stdio.h>
#include <stdbool.h>

#define HELPFUL_IMPLEMENTATION
#include "../libs/helpful_c/helpful.h"

#define MAX_LINE_LENGTH 1024

bool check_row_increment(int numbers[], int row_length)
{
    int previous = 0;
    int current = 0;
    for(int i = 0; i < row_length; i++)
    {
        if(i == 0) {
            previous = numbers[i];
            continue;
        }

        current = numbers[i];

        if(current < previous || current > (previous + 3) || current == previous)
        {
            return false;
        }
        previous = current;
    }

    return true;
}

bool check_row_decrement(int numbers[], int row_length)
{
    int previous = 0;
    int current = 0;
    for(int i = 0; i < row_length; i++)
    {
        if(i == 0) {
            previous = numbers[i];
            continue;
        }

        current = numbers[i];


        if(current > previous || (previous - current) > 3 || current == previous)
        {
            return false;
        }
        previous = current;
    }
    return true;
}

int main(void)
{
    int final = 0;
    char *input_text = NULL;
    int res = -1;
    //res = hf_read_file_to_buffer("./input_test.txt", &input_text, 1);
    res = hf_read_file_to_buffer("./input.txt", &input_text, 1);
    if(res == -1 || input_text == NULL)
    {
        return EXIT_FAILURE; 
    }

    char *line = input_text;

    int line_count = 0;
    // Process the buffer line by line
    while (line != NULL) {
        char *next_line = strchr(line, '\n');

        if(next_line != NULL)
        {
            line_count++;
            *next_line = '\0';
            next_line++;
        }

        if (strlen(line) > 0) {
            int numbers[100];
            int count = 0;

            char *token = strtok(line, " ");
            while (token != NULL) {
                // Dangerous conversion, but I am a cowboy
                numbers[count++] = atoi(token);
                token = strtok(NULL, " ");
            }

            if (count == 0 || count == 1) {
                line = next_line;
                continue; 
            }

            // Compare the first and last numbers
            int first = numbers[0];
            int last = numbers[count - 1];

            // Skip line and continue with the next line
            if (first == last) {
                line = next_line; 
                continue;
            }

            // Process the line only if it's not skipped
            if (first < last) {
                // Incrementing
                if(check_row_increment(numbers, count))
                    final++;
            }

            if (first > last) {
                // Decrementing
                if(check_row_decrement(numbers, count))
                    final++;
            }
        }

        line = next_line;
    }

    printf("line count check: %d\n", line_count);
    printf("final score: %d\n", final);

    free(input_text);
    
    return EXIT_SUCCESS;
}
