class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x=0,y=0;
        char direction='n';
        while(1){
            for(auto i:instructions){
            if(i=='G' && direction=='n'){
                y++;
            }
            else if(i=='G' && direction=='s'){
                y--;
            }
            else if(i=='G' && direction=='w'){
                x--;;
            }
            else if(i=='G' && direction=='e'){
                x++;
            }
            else if(i=='L'){
                if(direction=='n') direction='w';
                else if(direction=='w')direction='s';
                else if(direction=='s')direction='e';
                else direction='n';
            }
            else if(i=='R'){
                if(direction=='n') direction='e';
                else if(direction=='w')direction='n';
                else if(direction=='s')direction='w';
                else direction='s';
            }
        } 
        if(x==0 && y==0) return true;
            if(direction =='n')break;
        }
        if(x==0 && y==0) return true;
        return false;
    }
};