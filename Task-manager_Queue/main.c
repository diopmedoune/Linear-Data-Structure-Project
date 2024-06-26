#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "taskControl.h"

#define MIN_TASKS 1000
#define MAX_TASKS 10000
#define STEP 1000
#define NUM_TESTS 100

void executePerformanceTest(TaskQueue *task_queue, int num_tasks);

int main() {

    // Insertion de 2 taches 
    TaskQueue *task_queue = initializeTaskQueue();
    Task *task1 = createTask("DSA-Project", "Projet Algorithmique", 3, "2024-05-11", "2024-05-15");
    Task *task2 = createTask("Exam AnaVec", "Examen d'analyse vectoriel", 2, "2024-01-11", "2024-01-13");
    enqueueTask(task_queue, task1);
    enqueueTask(task_queue, task2);

    dequeueTask(task_queue);
    displayTaskQueue(task_queue);


    Task *searched_task = searchTaskByName(task_queue, "DSA-Project");
    if (searched_task != NULL) {
        displayTask(searched_task);
    }


    /*for (int num_tasks = MIN_TASKS; num_tasks <= MAX_TASKS; num_tasks += STEP) {
        TaskQueue *task_queue = initializeTaskQueue();
        executePerformanceTest(task_queue, num_tasks);
        freeTaskQueue(task_queue);
    }*/

    return 0;
}

void executePerformanceTest(TaskQueue *task_queue, int num_tasks) {
    struct timespec start, stop;
    float total_duration = 0.0;
    float average_duration = 0.0;

 

    for (int test = 0; test < NUM_TESTS; ++test) {
        // Mesurer le temps pour insérer les tâches
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int i = 0; i < num_tasks; ++i) {
            // Générer des tâches aléatoires
            char name[50];
            char description[100];
            int priority = rand() % 3 + 1;

            sprintf(name, "Task %d", i);
            sprintf(description, "Description of Task %d", i);

            Task *task = createTask(name, description, priority, "2024-06-11", "2024-06-15");
            enqueueTask(task_queue, task);
        }
        clock_gettime(CLOCK_MONOTONIC, &stop);

        float duration = (stop.tv_sec - start.tv_sec) * 1000.0 + (stop.tv_nsec - start.tv_nsec) / 1000000.0;
        total_duration += duration;

        // Mesurer le temps pour rechercher une tâche
        clock_gettime(CLOCK_MONOTONIC, &start);
        // Insérez ici votre code de recherche
        clock_gettime(CLOCK_MONOTONIC, &stop);

        duration = (stop.tv_sec - start.tv_sec) * 1000.0 + (stop.tv_nsec - start.tv_nsec) / 1000000.0;
        total_duration += duration;

        // Mesurer le temps pour supprimer une tâche
        clock_gettime(CLOCK_MONOTONIC, &start);
        // Insérez ici votre code de suppression
        clock_gettime(CLOCK_MONOTONIC, &stop);

        duration = (stop.tv_sec - start.tv_sec) * 1000.0 + (stop.tv_nsec - start.tv_nsec) / 1000000.0;
        total_duration += duration;
    }

    average_duration = total_duration / (3 * NUM_TESTS);  // Divisé par 3 pour les trois opérations (insertion, recherche, suppression)

    printf("Number of tasks: %d\n", num_tasks);
    printf("Average time for insertion: %.2f ms\n", average_duration);
    printf("Average time for search: %.2f ms\n", average_duration);  // Mettez à jour avec les résultats réels
    printf("Average time for removal: %.2f ms\n\n", average_duration);  // Mettez à jour avec les résultats réels
}
