#include "queue.h"
#include "dll.h"
#include "music_player.h"
#include <stdio.h>
#include <stdlib.h>

int searchcount=0;

playlist_t* create_playlist() // return a newly created doubly linked list
{
	// DO NOT MODIFY!!!
	playlist_t* playlist = (playlist_t*) malloc(sizeof(playlist_t));
	playlist->list = create_list();
	playlist->num_songs = 0;
	playlist->last_song = NULL;
	return playlist;
}

void delete_playlist(playlist_t* playlist) // delete the playlist
{
	// DO NOT MODIFY!!!
	delete_list(playlist->list);
	free(playlist);
}

music_queue_t* create_music_queue() // return a newly created queue
{
	// DO NOT MODIFY!!!
	return create_queue();
}

void clear_music_queue(music_queue_t* q) // clear the queue q
{	
	// DO NOT MODIFY!!!
	delete_queue(q);
}

void add_song(playlist_t* playlist, int song_id, int where) // TODO: add a song id to the end of the playlist
{
	if(where ==-2)
	{
		insert_back(playlist->list, song_id);
		playlist->num_songs += 1;
	}
	else if(where ==-1)
	{
		insert_front(playlist->list, song_id);
		playlist->num_songs +=1;
	}
	else if(where >= 0)
	{
		insert_after(playlist->list, song_id, where);
		playlist->num_songs += 1;
	}
}

void delete_song(playlist_t* playlist, int song_id) // TODO: remove song id from the playlist
{
	delete_node(playlist->list,song_id);
	playlist->num_songs -= 1;
}

song_t* search_song(playlist_t* playlist, int song_id) // TODO: return a pointer to the node where the song id is present in the playlist
{
	return (search(playlist->list,song_id));
}

void search_and_play(playlist_t* playlist, int song_id) // TODO: play the song with given song_id from the list(no need to bother about the queue. Call to this function should always play the given song and further calls to play_next and play_previous)
{
	song_t *p=playlist->list->head;
	while(p!=NULL)
	{
		if(p->data == song_id)
		{
			play_song(p->data);
			playlist->last_song=p;
			break;
		}
		p=p->next;
	}
}

void play_next(playlist_t* playlist, music_queue_t* q) // TODO: play the next song in the linked list if the queue is empty. If the queue if not empty, play from the queue
{
	if((q->front==NULL) && (playlist->list->head==NULL))
	{
		return;
	}
	else if((playlist->list->head!=NULL) && (q->front==NULL))
	{
		if(playlist->last_song==NULL)
		{
			playlist->last_song=playlist->list->head;
			play_song(playlist->last_song->data);
			return;
		}
		else
		{
			song_t *curr=playlist->last_song;
			if(curr->next==NULL)
			{
				playlist->last_song=playlist->list->head;
			}
			else
			{
				playlist->last_song=playlist->last_song->next;
			}
			search_and_play(playlist,playlist->last_song->data);
		}
	}
	else
	{
		if(playlist->last_song==NULL)
		{
			playlist->last_song=playlist->list->head;
			play_song(playlist->last_song->data);
			return;
		}
		else
		{
			play_song(dequeue(q));
		}
	}
}

void play_previous(playlist_t* playlist) // TODO: play the previous song from the linked list
{
	if(playlist->list->head == NULL)
	{
		return;
	}
	if(playlist->last_song == NULL)
	{
		playlist->last_song=playlist->list->tail;
		play_song(playlist->last_song->data);
	}
	else if(playlist->last_song->prev == NULL)
	{
		if(searchcount==1)
		{
			play_song(playlist->last_song->data);
			searchcount=0;
		}
		else
		{
			playlist->last_song=playlist->list->tail;
			play_song(playlist->last_song->data);
		}
	}
	else
	{
		if(searchcount == 1)
		{
			play_song(playlist->last_song->data);
			searchcount=0;
		}
		else
		{
			playlist->last_song=playlist->last_song->prev;
			play_song(playlist->last_song->data);
		}
	}
}

void play_from_queue(music_queue_t* q) // TODO: play a song from the queue
{
	play_song(dequeue(q));
}

void insert_to_queue(music_queue_t* q, int song_id) // TODO: insert a song id to the queue
{
	enqueue(q,song_id);
}

void reverse(playlist_t* playlist) // TODO: reverse the order of the songs in the given playlist. (Swap the nodes, not data)
{
	song_t *p=playlist->list->head;
	song_t *befp=NULL;
	if(p == NULL)
	{
		return;
	}
	while(p != NULL)
	{
		befp=p->prev;
		p->prev=p->next;
		p->next=befp;
		p=p->prev;
	}
	if(befp!=NULL)
	{
		playlist->list->head=befp->prev;
		p=playlist->list->head;
		while(p->next != NULL)
		{
			p=p->next;
		}
		playlist->list->tail=p;
	}
}

void k_swap(playlist_t* playlist, int k) // TODO: swap the node at position i with node at position i+k upto the point where i+k is less than the size of the linked list
{
	if(playlist->list->head==NULL)
	{
		return;
	}
	else if((playlist->list->head)==(playlist->list->tail))
	{
		return;
	}
	else if(k==1)
	{
		song_t *p=playlist->list->head;
		p->next->prev=NULL;
		playlist->list->head=p->next;
		p->prev=playlist->list->tail;
		playlist->list->tail->next=p;
		p->next=NULL;
	}
	else
	{
		for (int i = 0; (k + i) < playlist->list->size; i++)
		{
			int k1 = 0, k2 = 0;
			song_t *p1 = playlist->list->head;
			song_t *p2 = playlist->list->head;
			while (k1 != i)
			{
				p1 = p1->next;
				k1++;
			}
			while (k2 != (i + k))
			{
				p2 = p2->next;
				k2++;
			}
			song_t *p1prev = p1->prev;
			song_t *p1next = p1->next;
			if (p1 == playlist->list->head)
			{
				playlist->list->head = p2;
			}
			if (p2 == playlist->list->tail)
			{
				playlist->list->tail = p1;
			}
			p1->prev = p2->prev;
			p1->next = p2->next;
			p2->prev = p1prev;
			p2->next = p1next;
			if (p1->next != NULL)
			{
				p1->next->prev = p1;
			}
			if (p2->next != NULL)
			{
				p2->next->prev = p2;
			}
			if (p2->prev != NULL)
			{
				p2->prev->next = p2;
			}
			if (p1->prev != NULL)
			{
				p1->prev->next = p1;
			}
		}
	}
}

void shuffle(playlist_t* playlist, int k) // TODO: perform k_swap and reverse
{
	if(playlist->list->head != NULL)
	{
	k_swap(playlist,k);
	reverse(playlist);
	}
}

song_t* debug(playlist_t* playlist) // TODO: if the given linked list has a cycle, return the start of the cycle, else return null. Check cycles only in forward direction i.e with the next pointer. No need to check for cycles in the backward pointer.
{
	return playlist->list->tail->next;
}

void display_playlist(playlist_t* p) // Displays the playlist
{
	// DO NOT MODIFY!!!
	display_list(p->list);
}

void play_song(int song_id)
{
	// DO NOT MODIFY!!!
	printf("Playing: %d\n", song_id);
}

