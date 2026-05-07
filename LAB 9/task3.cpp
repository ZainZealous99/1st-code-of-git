#include <iostream>
using namespace std;

class node
{
public:
    int playerid;
    int score;

    node* next;

    node(int id, int s)
    {
        playerid = id;
        score = s;
        next = nullptr;
    }
};

class game
{
private:
    node* tail;
    node* current;

public:
    game()
    {
        tail = nullptr;
        current = nullptr;
    }

    void addplayer(int id, int score)
    {
        node* newnode = new node(id, score);

        if (tail == nullptr)
        {
            tail = newnode;
            tail->next = tail;
            current = tail;

            cout << "player added" << endl;
            return;
        }

        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;

        cout << "player added" << endl;
    }

    void removeplayer(int id)
    {
        if (tail == nullptr)
        {
            cout << "no players in game" << endl;
            return;
        }

        node* curr = tail->next;
        node* prev = tail;

        do
        {
            if (curr->playerid == id)
            {
                if (curr == tail && curr == tail->next)
                {
                    cout << "player removed" << endl;
                    delete curr;
                    tail = nullptr;
                    current = nullptr;
                    return;
                }

                prev->next = curr->next;

                if (curr == tail)
                {
                    tail = prev;
                }

                if (current == curr)
                {
                    current = curr->next;
                }

                delete curr;

                cout << "player removed" << endl;
                return;
            }

            prev = curr;
            curr = curr->next;

        } while (curr != tail->next);

        cout << "player not found" << endl;
    }

    void nextturn()
    {
        if (current == nullptr)
        {
            cout << "no players available" << endl;
            return;
        }

        cout << "current turn" << endl;
        cout << "player id " << current->playerid << endl;
        cout << "score " << current->score << endl;

        current = current->next;
    }

    void skipplayer()
    {
        if (current == nullptr)
        {
            cout << "no players available" << endl;
            return;
        }

        cout << "player skipped" << endl;
        cout << "player id " << current->playerid << endl;

        current = current->next;

        cout << "next player turn" << endl;
        cout << "player id " << current->playerid << endl;
        cout << "score " << current->score << endl;

        current = current->next;
    }

    void displayplayers()
    {
        if (tail == nullptr)
        {
            cout << "no players in game" << endl;
            return;
        }

        node* temp = tail->next;

        cout << "players in game" << endl;

        do
        {
            cout << "player id " << temp->playerid << endl;
            cout << "score " << temp->score << endl;
            cout << endl;

            temp = temp->next;

        } while (temp != tail->next);
    }

    void checkwinner()
    {
        if (tail != nullptr && tail == tail->next)
        {
            cout << "game ended" << endl;
            cout << "winner player id " << tail->playerid << endl;
            cout << "winner score " << tail->score << endl;
        }
    }
};

int main()
{
    game g;

    g.addplayer(1, 100);
    g.addplayer(2, 150);
    g.addplayer(3, 200);
    g.addplayer(4, 250);

    cout << endl;
    g.displayplayers();

    cout << "next player turn" << endl;
    g.nextturn();

    cout << endl;
    cout << "skip player turn" << endl;
    g.skipplayer();

    cout << endl;
    cout << "removing player 2" << endl;
    g.removeplayer(2);

    cout << endl;
    g.displayplayers();

    cout << "removing player 1" << endl;
    g.removeplayer(1);

    cout << "removing player 3" << endl;
    g.removeplayer(3);

    cout << endl;
    g.displayplayers();

    g.checkwinner();

    return 0;
}