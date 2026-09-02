#include <iostream>
#include <string>
using namespace std;

struct Song
{
    string title;
    Song* prev;
    Song* next;

    Song(string t)
    {
        title = t;
        next = NULL;
        prev = NULL;
    }
};

class Playlist
{
private:
    Song* head;
    Song* tail;
    Song* current;

public:
    Playlist()
    {
        head = NULL;
        tail = NULL;
        current = NULL;
    }

    void addSong(string title)
    {
        Song* newSong = new Song(title);

        if (head == NULL)
        {
            head = tail = current = newSong;
        }
        else
        {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }

        cout << "Song Added: " << title << endl;
    }

    void showCurrent()
    {
        if (current == NULL)
        {
            cout << "Playlist is empty.\n";
        }
        else
        {
            cout << "Playing: " << current->title << endl;
        }
    }

    void nextSong()
    {
        if (current == NULL)
        {
            cout << "Playlist is empty.\n";
        }
        else if (current->next == NULL)
        {
            cout << "Already at the last song.\n";
        }
        else
        {
            current = current->next;
            showCurrent();
        }
    }

    void previousSong()
    {
        if (current == NULL)
        {
            cout << "Playlist is empty.\n";
        }
        else if (current->prev == NULL)
        {
            cout << "Already at the first song.\n";
        }
        else
        {
            current = current->prev;
            showCurrent();
        }
    }

    void displayPlaylist()
    {
        Song* temp = head;

        cout << "\nPlaylist:\n";

        while (temp != NULL)
        {
            cout << temp->title << endl;
            temp = temp->next;
        }
    }

    ~Playlist()
    {
        Song* temp = head;

        while (temp != NULL)
        {
            Song* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main()
{
    Playlist playlist;

    playlist.addSong("song1");
    playlist.addSong("song2");
    playlist.addSong("song3");
    playlist.addSong("song4");

    playlist.displayPlaylist();

    cout << "\n";
    playlist.showCurrent();

    cout << "\nMoving forward:\n";
    playlist.nextSong();
    playlist.nextSong();

    cout << "\nMoving backward:\n";
    playlist.previousSong();

    return 0;
}

