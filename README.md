# Music_Player-with-Data-Structures

Software engineering involves more than just programming. It involves analysing and modifying existing software as well as designing, constructing and testing end-user applications that meet user needs. The current course, Data Structures and its Applications plays a major role in the low-level design of any software system by choosing the appropriate data structures in the right places, for efficient implementation. Let us look at one such system and try to make it efficient by implementing it with appropriate data structures.
For this assignment, we are working on a music-streaming system(like Spotify). The current system has been identified to have a few bugs in a few places, so we need to write the code for the functions described in the document later. But first, let us get to know more about the system we will be working on.

# Logical Units and Terminlogies of the system

1. Song: Each song is identified by a unique non-negative integer identifier.
2. Playlist: A playlist is a collection of songs. We can add songs, delete songs and search for songs from it.
3. Play Queue: A song queue, which specifies the prioritised order in which the songs need to play next. If the queue is non-empty, the next song to be played is always from this queue and not from the playlist.
4. Shuffling: Shuffle the order of songs stored in the playlist. Shuffling is done by a combination of KSwap and reverse operations.
5. KSwap: Given an integer k, swap the node at position i with the node at position i+k up to the point where i+k is less than the size of the linked list i.e swap for the nodes that satisfy: 0 <= i+k < n where n is the length of the linked list, given 0 <= i < n and 0 <= k < n
