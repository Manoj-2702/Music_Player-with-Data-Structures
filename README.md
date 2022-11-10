# Music_Player-with-Data-Structures

Software engineering involves more than just programming. It involves analysing and modifying existing software as well as designing, constructing and testing end-user applications that meet user needs. The current course, Data Structures and its Applications plays a major role in the low-level design of any software system by choosing the appropriate data structures in the right places, for efficient implementation. Let us look at one such system and try to make it efficient by implementing it with appropriate data structures.
For this assignment, we are working on a music-streaming system(like Spotify). The current system has been identified to have a few bugs in a few places, so we need to write the code for the functions described in the document later. But first, let us get to know more about the system we will be working on.

# Logical Units and Terminlogies of the system

1. <b>Song</b>: Each song is identified by a unique non-negative integer identifier.
2. <b>Playlist</b>: A playlist is a collection of songs. We can add songs, delete songs and search for songs from it.
3. <b>Play Queue</b>: A song queue, which specifies the prioritised order in which the songs need to play next. If the queue is non-empty, the next song to be played is always from this queue and not from the playlist.
4. <b>Shuffling</b>: Shuffle the order of songs stored in the playlist. Shuffling is done by a combination of KSwap and reverse operations.
5. <b>KSwap</b>: Given an integer k, swap the node at position i with the node at position i+k up to the point where i+k is less than the size of the linked list i.e swap for the nodes that satisfy: 0 <= i+k < n where n is the length of the linked list, given 0 <= i < n and 0 <= k < n. <br>

![k-swap](https://user-images.githubusercontent.com/103581128/201145106-2ef97bc7-4fb8-41b1-aea7-0caaaebd8d4c.png)


6. <b>Loops</b>: Few of the old playlists are found to have a loop or a cycle in the linked list due to buggy implementation.<br>
![loop](https://user-images.githubusercontent.com/103581128/201145428-ea2a5229-23c3-4373-bc37-68b3786de139.png)


# Choice of data structures for implementing the problem at hand:
1) <b>Playlist</b>: The ideal data structure of choice for modelling a playlist would be a doubly linked list. This would come in handy as new songs can be added or the old ones can be removed from the playlist at any point in a doubly linked list. Also, it should support playing(querying) the previous song, next song and (current + i)’th song on the playlist.
2) <b>Play Queue</b>: A queue abstract data-type to follow FIFO. The choice of implementation of the ADT can be either a linked list or an array. For this assignment, we stick on to the linked list implementation of the queue as it gives us the flexibility of dynamically changing the size of the data structure.


# Learning Outcomes

1. Cope with abstractions depicting real-world entities.
2. Choosing appropriate data-structures for the right design.
3. Writing reusable and modular code.
4. Strengthen memory management in C and avoid dangling pointers and memoryleaks while using dynamic data-structures like linked lists.
5. Getting familiar with the various traversal techniques of a linked list (Eg: slow-fastpointer traversals)
6. Rearranging the linked list pointers.
7. Optional: Recursive algorithms on linked lists. Eg: Reversing a linked list is easier tocode using recursion.


