#include <stdlib.h>
#include <iostream>
#include <time.h>

const int N = 50;
const int P = 50;
const int GENERATIONS = 50;
const float MUTRATE = 1;

typedef struct {
	int gene[N];
	int fitness;
} individual;


int GenerateFitnessValues(individual ind)
{
	int fitness = 0;
	for (int i = 0; i < N; i++) {
		if (ind.gene[i] == 1)
			fitness += 1;
	}
	return fitness;
}


void PrintPopulationFitness(individual population[P])
{
	int t = 0;

	std::cout <<  "( ";

	for (int i = 0; i < P; i++)
	{
		std::cout << "" << population[i].fitness << " ";

		t = t + population[i].fitness;

	}
	std::cout << ") Total Fitness - " << t << std::endl;
}


void PrintPopulationGenes(individual population[P])
{

	for (int i = 0; i < P; i++)
	{
		std::cout << "Individual " << i << " - ";
		for (int j = 0; j < N; j++)
		{

			std::cout << "" << population[i].gene[j];

		}

		std::cout << std::endl;
	}
}


int main()
{ 
	srand(time(0));

	individual population[P];
	individual offspring[P];



	//Create initial population
	for (int i = 0; i < P; i++)
	{
		for (int j = 0; j < N; j++)
		{
			population[i].gene[j] = rand() % 2;
		}
		population[i].fitness = 0;
	}

	std::cout << "Initial Genes" << std::endl;
	PrintPopulationGenes(population);

	//5 Generations
	for (int generation = 0; generation < GENERATIONS; ++generation) {
		
		

		std::cout << "--------------------------------------------------------------Generation" << generation + 1<< "-------------------------------------------------------" << std::endl;

		//Get fitness values for each individual
		for (int i = 0; i < P; i++)
		{
			population[i].fitness = GenerateFitnessValues(population[i]);
		}

		std::cout << "Population" << std::endl;
		PrintPopulationFitness(population);

		//Selection
		for (int i = 0; i < P; i++) {
			int parent1 = rand() % P;
			int parent2 = rand() % P;
			if (population[parent1].fitness > population[parent2].fitness)
				offspring[i] = population[parent1];
			else
				offspring[i] = population[parent2];
		}


		//Crossover
		individual temp;
		for (int i = 0; i < P; i += 2) {
			temp = offspring[i];
			int crosspoint = rand() % N;
			for (int j = crosspoint; j < N; j++) {
				offspring[i].gene[j] = offspring[i + 1].gene[j];
				offspring[i + 1].gene[j] = temp.gene[j];
			}
		}


		//Mutation
		for (int i = 0; i < P; i++) {
			for (int j = 0; j < N; j++) {
				if (rand() < MUTRATE) {
					if (offspring[i].gene[j] == 1) offspring[i].gene[j] = 0;
					else offspring[i].gene[j] = 1;
				}
			}
		}


		std::cout << "Offspring" << std::endl;
		PrintPopulationFitness(offspring);

		//Copy offspring to population
		for (int i = 0; i < P; i++)
		{
			population[i] = offspring[i];
		}

	}

	//std::cout << "Final Genes" << std::endl;
	//PrintPopulationGenes(population);

	return 0;

}