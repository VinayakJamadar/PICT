#include<bits/stdc++.h>
using namespace std;

class Election{
    public:
        int n, coordinator, initiator;
        vector<bool> processStatus;

        Election() {
            n = 0;
            coordinator = 0;
            initiator = 0;
            processStatus = vector<bool> (0, 0);
        }

        void readN() {
            cout<<"\nEnter number of process : ";
            cin>>n;
        }

        void readInitiator() {
            cout<<"\nEnter initiator of Election (Between 0 to "<<n-1<<") : ";
            cin>>initiator;
            if(initiator<0 or initiator>n-1) {
                cout<<"\nEnter a valid initiator.";
                readInitiator();
            }
            else if(processStatus[initiator] == 0) {
                cout<<"\nProcess "<<initiator<<" is not responding.\n";
                cout<<"Enter a initiator who is responding\n";
                readInitiator();
            }
        }

        void readProcessStatus() {
            for (int i = 0; i < n; i++)
            {
                int status;
                cout<<"\nEnter status of "<<i<<" process (0/1) : ";
                cin>>status;
                processStatus.push_back(status);
            }
        }

        void printCoordinator() {
            cout<<"\nCoordinator of Election is : "<<coordinator<<endl;
        }
};

class Ring: public Election {
    public:
        void ringAlgo() {
            vector<int> tokens(0);
            int from = initiator, to = initiator+1, count = 0;
            coordinator = initiator;
            tokens.push_back(initiator);
            cout<<"\ntokens : [ "<<tokens[0]<<" ]"<<endl;
            while(count < n) {
                if(processStatus[to]){
                    coordinator = max(coordinator, to);
                    cout<<"\nMessage passed from process"<<from<<" to "<<to<<endl;
                    tokens.push_back(to);
                    cout<<"\ntokens : [ ";
                    for (int i = 0; i < tokens.size(); i++)
                    {
                        cout<<tokens[i]<<" ";
                    }
                    cout<<"]"<<endl;
                    from = to;
                }
                to = (++to)%n;
                ++count;
            }
        }
};

class Bully: public Election {
    public:
        vector<int> processPriority;

        Bully() {
            processPriority = vector<int> (0, 0);
        }

        void readProcessPriority() {
            for (int i = 0; i < n; i++)
            {
                int priority;
                cout<<"\nEnter priority of "<<i<<" process : ";
                cin>>priority;
                processPriority.push_back(priority);
            }
        }

        void bullyAlgo(int e) {
            coordinator = e;
            for(int i = 0; i < n; i++) {
                if(processPriority[e] < processPriority[i]) {
                    cout<<"\nElection Message is sent from "<<e<<" to "<<i<<endl;
                    if(processStatus[i]) {
                        bullyAlgo(i);
                    }
                }
            }
        }
};

int main(){
    int option;
    while(1) {
        cout<<"\nMenu for Election Algorithms\n\n1) Ring\n2) Bully\n-1) Exit"<<endl;

        cout<<"\nEnter option from above menu : ";
        cin>>option;

        if(option == 1) {
            Ring R;
            R.readN();
            R.readProcessStatus();
            R.readInitiator();
            R.ringAlgo();
            R.printCoordinator();
        }
        else if(option == 2) {
            Bully B;
            B.readN();
            B.readProcessStatus();
            B.readProcessPriority();
            B.readInitiator();
            B.bullyAlgo(B.initiator);
            B.printCoordinator();
        }
        else if(option == -1) {
            cout<<"\nExit";
            break;
        }
        else {
            cout<<"\nEnter a valid input\n";
        }
    }
    return 0;
}