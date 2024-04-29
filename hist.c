#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int score;
    int frequency;
} freq;

void readScores(int* scores, int* count) {
    // reads scores from the user until EOF (End Of File) is encountered.
    // The scores are stored in the scores array and the total number of
    // scores read is stSored in count.
    printf("Enter scores:\n");
    while(scanf("%d", &scores[*count]) != EOF) {
        (*count)++;
    }
}

void displayScores(int* scores, int count) {
    // displays all the scores read from the user in the order they are read
    for(int i = 0; i < count; i++){
        printf("score %d: %d\n", i, scores[i]);
    }
    printf("\n");
}

void calcHistogram(int* scores, int count, freq* histogram, int* histSize) {
    // calculates the frequency of each score and stores the result in the
    // histogram array. The total number of unique scores is stored in histSize
    for (int i = 0; i < count; i++){
        int found = 0;
        for (int j = 0; j < *histSize; j++){
            if (scores[i] == histogram[j].score){
                histogram[j].frequency++;
                found = 1;
                break;
            }
        }
        if (!found){
            histogram[*histSize].score = scores[i];
            histogram[*histSize].frequency = 1;
            (*histSize)++;
        }
    }
}

void displayHistogram(freq* histogram, int* histSize){
    // displays the frequency of each score in the histogram
    for (int i = 0; i < histSize; i++){
        printf("score %d: %d \n ", histogram[i].score, histogram[i].frequency);
    }
    printf("\n");
}

void sortHistogram(freq* histogram, int* histSize) {
    // sorts the histogram in descending order of frequency using selection
    // sort, putting the max into the sorted subarray each loop
    for(int i = 0; i < histSize - 1; i++) {
        int max = i;
        for(int j = i + 1; j < *histSize; j++) {
            if(histogram[j].frequency > histogram[max].frequency) {
                max = j;
            }
        }
        freq temp = histogram[i];
        histogram[i] = histogram[max];
        histogram[max] = temp;
    }
}

int main() {
    int scores[100], count = 0;
    freq histogram[100];
    int histSize = 0;
    readScores(scores, &count);
    displayScores(scores, count);
    calcHistogram(scores, count, histogram, &histSize);
    displayHistogram(histogram, histSize); 
    sortHistogram(histogram, histSize); 
    displayHistogram(histogram, histSize); 
    return 0;
}

