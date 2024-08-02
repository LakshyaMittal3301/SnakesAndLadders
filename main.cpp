#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unordered_map<int, int> mp;
    for(int i = 0; i <= 100; i++) mp[i] = i;
    
    int num_of_snakes; 
    cin >> num_of_snakes;
    for(int i = 0; i < num_of_snakes; i++){
        int snake_start, snake_end;
        cin >> snake_start >> snake_end;
        mp[snake_start] = snake_end;
    }

    int num_of_ladders;
    cin >> num_of_ladders;
    for(int i = 0; i < num_of_ladders; i++){
        int ladder_start, ladder_end;
        cin >> ladder_start >> ladder_end;
        mp[ladder_start] = ladder_end;
    }

    int num_of_players;
    cin >> num_of_players;
    vector<string> player_names;
    vector<int> curr_position(num_of_players, 0);
    for(int i = 0; i < num_of_players; i++){
        string player_name;
        cin >> player_name;
        player_names.push_back(player_name);
    }

    int num_rolled; 
    cin >> num_rolled;
    int curr_player = -1;
    while(num_rolled != 0){
        curr_player = (curr_player + 1) % num_of_players;
        int actual_roll = num_rolled;
        if(curr_position[curr_player] + num_rolled > 100){
            num_rolled = 0;
        }
        int initial_position = curr_position[curr_player];
        curr_position[curr_player] += num_rolled;
        while(curr_position[curr_player] != mp[curr_position[curr_player]]){
            curr_position[curr_player] = mp[curr_position[curr_player]];
        }
        cout << player_names[curr_player] << " rolled a " << actual_roll << " and moved from " << initial_position << " to " <<  curr_position[curr_player] << "\n";
        if(curr_position[curr_player] == 100){
            cout << player_names[curr_player] << " wins the game" << "\n";
            break;
        }
        cin >> num_rolled;
    }

    return 0;
}