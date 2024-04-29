#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char* word;
    int frequency;
} Histogram;

char** readWords(int* count) {
    // reads words from the standard input until EOF  
    printf("Enter words:\n");
    char** words = (char**)malloc(sizeof(char*)*100);
    char temp[101];
    while(scanf("%s", temp) != EOF) {
        words[*count] = (char*)malloc((strlen(temp) + 1)*sizeof(char)); // strlen(temp) returns the length of the string temp
        strcpy(words[*count], temp); // strcpy(dest, src) copies the string src to dest
        (*count)++;
    }
    return words;
}

void displayWords(char** words, int count) {
    // prints all the words stored in the `words` array along with their indices
    for(int i = 0; i < count; i++){
        printf("word %d: %s\n", i, words[i]);
    }
    printf("\n");
}

int calcHistogram(char** words, int count, Histogram** histogram) {
    // calculates the frequency of each unique word in the `words` array
    // stores this information in an array. returns the size of the array
    *histogram = (Histogram*)malloc(sizeof(Histogram)*100);
    int histSize = 0;
    for (int i = 0; i < count; i++){
        int found = 0;
        for (int j = 0; j < histSize; j++){
            if (strcmp(words[i], (*histogram)[j].word) == 0){
                (*histogram)[j].frequency++;
                found = 1;
                break;
            }
        }
        if (!found){
            (*histogram)[histSize].word = (char*)malloc(strlen(words[i]) + 1); // strlen(words[i]) returns the length of the string words[i]
            strcpy((*histogram)[histSize].word, words[i]); // strcpy(dest, src) copies the string src to dest
            (*histogram)[histSize].frequency = 1;
            histSize++;
        }
    }
    return histSize;
}

void displayHistogram(Histogram* histogram, int histSize){
    // prints each word in the array along with its frequency
    for (int i = 0; i < histSize; i++){
        printf("word %s: %d \n ", histogram[i].word, histogram[i].frequency);
    }
    printf("\n");
}

void sortHistogram(Histogram* histogram, int histSize) {
    // sorts the array in descending order based on the frequency of each word
    // uses a simple selection sort algorithm for sorting
    for(int i = 0; i < histSize - 1; i++) {
        int max = i;
        for(int j = i + 1; j < histSize; j++) {
            if(histogram[j].frequency > histogram[max].frequency) {
                max = j;
            }
        }
        Histogram temp = histogram[i];
        histogram[i] = histogram[max];
        histogram[max] = temp;
    }
}

int main() {
    int count = 0;
    char** words = readWords(&count);
    displayWords(words, count);
    Histogram* histogram;
    int histSize = calcHistogram(words, count, &histogram);
    displayHistogram(histogram, histSize); 
    sortHistogram(histogram, histSize); 
    displayHistogram(histogram, histSize); 
    for(int i = 0; i < count; i++) {
        free(words[i]);
    }
    free(words);
    for(int i = 0; i < histSize; i++) {
        free(histogram[i].word);
    }
    free(histogram);
    return 0;
}

