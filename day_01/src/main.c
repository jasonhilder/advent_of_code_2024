#include <stdbool.h>
#include <stdio.h>

#define HELPFUL_IMPLEMENTATION
#include "../libs/helpful.h"

#define STB_DS_IMPLEMENTATION
#include "../libs/stb_ds.h"

int int_compare(const void* a, const void* b) 
{
    // If a is smaller, positive value will be returned
    return (*(int*)a - *(int*)b);
}

int part_one(bool test)
{
    int *l_array = NULL;
    int *r_array = NULL;
    int total = 0;
    char *input_text = NULL;

    int res = 0;
    if(test) {
        res = hf_read_file_to_buffer("./input_test.txt", &input_text);
    } else {
        res = hf_read_file_to_buffer("./input.txt", &input_text);
    }

    if (res != 0 || input_text == NULL) {
        return EXIT_FAILURE;
    }

    char *line = strtok(input_text, "\n");
    while (line != NULL) {

        // Tokenize each line by space to extract numbers
        int first_num, second_num;
        if (sscanf(line, "%d %d", &first_num, &second_num) == 2) {
            arrput(l_array, first_num);
            arrput(r_array, second_num);
        }

        // Get the next line
        line = strtok(NULL, "\n");
    }

    qsort(l_array, arrlen(l_array), sizeof(int), int_compare);
    qsort(r_array, arrlen(r_array), sizeof(int), int_compare);

    for(int i = 0; i < arrlen(l_array); i++)
    {
        int res = l_array[i] - r_array[i];
        total += abs(res);
    }

    free(input_text);
    arrfree(l_array);
    arrfree(r_array);
    return total;
}

int part_two(bool test)
{
    int *l_array = NULL;
    int *r_array = NULL;
    int total = 0;
    char *input_text = NULL;

    int res = 0;
    if(test) {
        res = hf_read_file_to_buffer("./input_test.txt", &input_text);
    } else {
        res = hf_read_file_to_buffer("./input.txt", &input_text);
    }

    if (res != 0 || input_text == NULL) {
        return EXIT_FAILURE;
    }

    char *line = strtok(input_text, "\n");
    while (line != NULL) {

        // Tokenize each line by space to extract numbers
        int first_num, second_num;
        if (sscanf(line, "%d %d", &first_num, &second_num) == 2) {
            arrput(l_array, first_num);
            arrput(r_array, second_num);
        }

        // Get the next line
        line = strtok(NULL, "\n");
    }

    qsort(l_array, arrlen(l_array), sizeof(int), int_compare);
    qsort(r_array, arrlen(r_array), sizeof(int), int_compare);

    for(int i = 0; i < arrlen(l_array); i++)
    {
        int current_count = 0;
        int current_num = l_array[i];

        for(int j = 0; j < arrlen(r_array); j++)
        {
            if(r_array[j] == current_num)
            {
                current_count += 1;
            }
        }

        int res = l_array[i] * current_count;
        total += abs(res);
        current_count = 0;
    }

    free(input_text);
    arrfree(l_array);
    arrfree(r_array);
    return total;
}

int main(void)
{
    int total_one = part_one(false);
    printf("%d\n", total_one);

    int total_two = part_two(false);
    printf("%d\n", total_two);
}