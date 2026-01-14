class Solution {
public:
    struct Event {
        int type, l, r;
        double y;
    };

    struct SegTree {
        int n;
        vector<int> cnt;
        vector<long long> len;
        vector<long long> xs;
        SegTree() {}
        SegTree(const vector<long long>& xs_) : xs(xs_) {
            n = max(0, (int)xs.size() - 1);
            if(n > 0){
                cnt.assign(4*n+5,0);
                len.assign(4*n+5,0);
            }
        }
        void update(int node,int l,int r,int ul,int ur,int val){
            if(ul>=r || ur<=l) return;
            if(ul<=l && r<=ur) cnt[node]+=val;
            else{
                int mid=(l+r)/2;
                update(node*2,l,mid,ul,ur,val);
                update(node*2+1,mid,r,ul,ur,val);
            }
            if(cnt[node]>0) len[node]=xs[r]-xs[l];
            else if(l+1==r) len[node]=0;
            else len[node]=len[node*2]+len[node*2+1];
        }
        void add(int L,int R,int v){
            if(n==0) return;
            update(1,0,n,L,R,v);
        }
        long long query() const{
            return n==0 ? 0 : len[1];
        }
    };

    double separateSquares(vector<vector<int>>& squares){
        vector<Event> events;
        vector<long long> xs;
        for(auto &s:squares){
            int x=s[0], y=s[1], l=s[2];
            events.push_back({1,x,x+l,(double)y});
            events.push_back({-1,x,x+l,(double)(y+l)});
            xs.push_back(x);
            xs.push_back(x+l);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        if(xs.size()<2) return 0.0;

        sort(events.begin(), events.end(), [](const Event &a,const Event &b){
            if(a.y!=b.y) return a.y<b.y;
            return a.type>b.type;
        });

        SegTree seg(xs);
        double total_area=0;
        double prev_y=events[0].y;
        for(auto &e:events){
            double h=e.y-prev_y;
            if(h>0) total_area+=seg.query()*h;
            int L=lower_bound(xs.begin(),xs.end(),(long long)e.l)-xs.begin();
            int R=lower_bound(xs.begin(),xs.end(),(long long)e.r)-xs.begin();
            if(L<R) seg.add(L,R,e.type);
            prev_y=e.y;
        }

        double half_area = total_area / 2.0;
        seg = SegTree(xs);
        prev_y = events[0].y;
        double area_accum = 0;
        for(auto &e:events){
            double h = e.y-prev_y;
            if(h>0) area_accum += seg.query()*h;
            if(area_accum >= half_area){
                double extra = area_accum - half_area;
                double line = e.y - extra / seg.query();
                return line;
            }
            int L=lower_bound(xs.begin(),xs.end(),(long long)e.l)-xs.begin();
            int R=lower_bound(xs.begin(),xs.end(),(long long)e.r)-xs.begin();
            if(L<R) seg.add(L,R,e.type);
            prev_y = e.y;
        }
        return prev_y;
    }
};
