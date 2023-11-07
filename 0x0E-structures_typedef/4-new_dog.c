#include "dog.h"
#include <stdlib.h>
#include <string.h>

/**
 * new_dog - create a new element of type struct dog
 * @name: name of new dog
 * @age: age of new dog
 * @owner: owner of new dog
 *
 * Return: pointer to the new struct dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;
	char *dog_name, *dog_owner;

	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
		return (NULL);

	dog_name = malloc(strlen(name) + 1);
	if (dog_name == NULL)
	{
		free(new_dog);
		return (NULL);
	}

	dog_owner = malloc(strlen(owner) + 1);
	if (dog_owner == NULL)
	{
		free(dog_name);
		free(new_dog);
		return (NULL);
	}

	strcpy(dog_name, name);
	strcpy(dog_owner, owner);

	new_dog->name = dog_name;
	new_dog->owner = dog_owner;
	new_dog->age = age;

	return (new_dog);
}
