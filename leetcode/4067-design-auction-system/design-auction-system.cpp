class AuctionSystem {
public:
    unordered_map<long long, int> mp;
    unordered_map<int, map<int, set<int>>> items;

    long long key(int u, int i) {
        return (long long)i << 32 | u;
    }

    void addBid(int userId, int itemId, int bidAmount) {
        long long k = key(userId, itemId);
        if (mp.count(k)) {
            int old = mp[k];
            items[itemId][old].erase(userId);
            if (items[itemId][old].empty())
                items[itemId].erase(old);
        }
        mp[k] = bidAmount;
        items[itemId][bidAmount].insert(userId);
    }

    void updateBid(int userId, int itemId, int newAmount) {
        addBid(userId, itemId, newAmount);
    }

    void removeBid(int userId, int itemId) {
        long long k = key(userId, itemId);
        int amt = mp[k];
        mp.erase(k);
        items[itemId][amt].erase(userId);
        if (items[itemId][amt].empty())
            items[itemId].erase(amt);
    }
    int getHighestBidder(int itemId) {
        if (!items.count(itemId)) return -1;
        auto &m = items[itemId];
        auto it = m.rbegin();
        if(m.begin() == m.end())
            return -1;  
        return *it->second.rbegin();    
    }
};
