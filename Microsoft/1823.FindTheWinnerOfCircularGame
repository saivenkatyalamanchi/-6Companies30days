class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> game;

        for(int i=1;i<=n;i++){
            game.push(i);
        }

        while(game.size() > 1){
            for(int i=1;i<k;i++){
                int num = game.front();
                game.pop();
                game.push(num);
            }

            game.pop();
        }

        return game.front();
    }
};