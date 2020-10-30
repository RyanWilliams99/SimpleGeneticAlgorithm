#include <stdlib.h>
#include <iostream>
#include <time.h>

const int N = 10;
const int P = 100;


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

	int t = 0;

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
	for (int i = 0; i < 15; ++i) {
		
		

		std::cout << "--------------------------------------------------------------Generation" << i + 1<< "-------------------------------------------------------" << std::endl;

		for (int i = 0; i < P; i++)
		{
			population[i].fitness = GenerateFitnessValues(population[i]);
		}

		std::cout << "Population" << std::endl;
		PrintPopulationFitness(population);

		for (int i = 0; i < P; i++) {
			int parent1 = rand() % P;
			int parent2 = rand() % P;
			if (population[parent1].fitness > population[parent2].fitness)
				offspring[i] = population[parent1];
			else
				offspring[i] = population[parent2];
		}


		std::cout << "Offspring" << std::endl;
		PrintPopulationFitness(offspring);

		//Copy offspring to population

		for (int i = 0; i < P; i++)
		{
			population[i] = offspring[i];
		}

	}

	std::cout << "Final Genes" << std::endl;
	PrintPopulationGenes(population);

	return 0;

}