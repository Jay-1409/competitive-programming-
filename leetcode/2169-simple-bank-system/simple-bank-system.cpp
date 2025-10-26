class Bank {
public:
    vector<long long> acnt;
    int cnt_n = 0;
    Bank(vector<long long>& balance) {
        for(auto &i : balance)
            acnt.push_back(i);
        cnt_n = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 > cnt_n || account2 > cnt_n)
            return false;
        if(acnt[account1 - 1] - money >= 0){
            acnt[account1 - 1] -= money;
            acnt[account2 - 1] += money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account > cnt_n)
            return false;
        acnt[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account > cnt_n)
            return false;
        if(acnt[account - 1] - money >= 0) {
            acnt[account - 1] -= money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */