#include "lists.h"
/**
 * insert_node - function that insert a number into a sorted singly linked list
 * @head: head list
 * @number: node to insert
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *newNode;
    listint_t *currentNode;

    currentNode = *head;
    newNode = malloc(sizeof(listint_t));
    if (newNode)
    {
        newNode->n = number;
        newNode->next =NULL;

        if (*head == NULL || (*head)->n >= newNode->n)
        {
            newNode->next = *head;
            *head = newNode;
        }
        else
        {
            while (currentNode->next && currentNode->next->n < newNode->n)
			{
				currentNode = currentNode->next;
			}
			newNode->next = currentNode->next;
			currentNode->next = newNode;
        }
        return (newNode);
        
    }
    return (NULL);
}