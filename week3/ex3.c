#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

int insert_node(struct node *head, struct node *newnode, struct node *prevnode)
{	
	struct node *tmp_node = head;
	while (tmp_node != prevnode)
	{
		tmp_node = tmp_node->next;
		if (tmp_node == NULL){
			printf("ERROR\n");
			return 0;
		}
	}
	tmp_node = prevnode->next;
	prevnode->next = newnode;
	newnode->next = tmp_node;
	return 1;
}

int delete_node(struct node *head, struct node *delnode){
	struct node *tmp_node = head;
	while (tmp_node->next != delnode)
	{
		tmp_node = tmp_node->next;
		if (tmp_node->next == NULL){
			printf("ERROR\n");
			return 0;
		}
	}
	tmp_node->next = delnode->next;
	return 1;	
}


void print_list(struct node *head)
{
	struct node *tmp_node = head;
	while (tmp_node != NULL){
		printf("%d\n", tmp_node->value);
		tmp_node = tmp_node->next;
	}
}

int main()
{
	struct node *head = (struct node*)malloc(sizeof(*head));
	head->value = 4;

	struct node *node_1 = (struct node*)malloc(sizeof(*node_1));
	node_1->value = 1;

	struct node *node_2 = (struct node*)malloc(sizeof(*node_2));
	node_2->value = 2;

	struct node *node_3 = (struct node*)malloc(sizeof(*node_3));
	node_3->value = 3;

	insert_node(head, node_1, head);

	insert_node(head, node_2, node_1);
	
	printf("Initial structure:\n");
	print_list(head);
	
	printf("Insert node after node_2:\n");
	insert_node(head, node_3, node_1);
	print_list(head);

	printf("Delete node_2:\n");
	delete_node(head, node_1);
	print_list(head);

	return 0;
}
