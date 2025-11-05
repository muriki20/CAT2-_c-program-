// c program 
/*
Name:moses
reg:CT100/G/26258/25
description:program reading procesin and writing interger to file
}
*/


   #include <stdio.h>

// Function to input 10 integers and store them in "input.txt"
void write_to_input_file() {
    FILE *file = fopen("input.txt", "w");
    if (file == NULL) {
        printf("Error opening input.txt for writing.\n");
        return;
    }
    int num;
    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &num);
        fprintf(file, "%d\n", num);
    }
    fclose(file);
}

// Function to read integers from "input.txt", calculate sum and average, and write to "output.txt"
void process_and_write_to_output_file() {
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input.txt for reading.\n");
        return;
    }
    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output.txt for writing.\n");
        fclose(input_file);
        return;
    }
    int sum = 0, count = 0, num;
    while (fscanf(input_file, "%d", &num) == 1) {
        sum += num;
        count++;
    }
    float average = count > 0 ? (float)sum / count : 0;
    fprintf(output_file, "Sum: %d\nAverage: %.2f\n", sum, average);
    fclose(input_file);
    fclose(output_file);
}

// Function to read and display contents of "input.txt" and "output.txt"
void display_files_content() {
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input.txt for reading.\n");
    } else {
        printf("Contents of input.txt:\n");
        int num;
        while (fscanf(input_file, "%d", &num) == 1) {
            printf("%d\n", num);
        }
        fclose(input_file);
    }

    FILE *output_file = fopen("output.txt", "r");
    if (output_file == NULL) {
        printf("Error opening output.txt for reading.\n");
    } else {
        printf("\nContents of output.txt:\n");
        char line[100];
        while (fgets(line, sizeof(line), output_file)) {
            printf("%s", line);
        }
        fclose(output_file);
    }
}

int main() {
    write_to_input_file();
    process_and_write_to_output_file();
    display_files_content();
    return 0;
}