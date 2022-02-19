template <typename H> struct myque
{
    int sz=gh-6,l,r;
    H deqe[gh];
    myque(){l=1;r=0;}
    inline bool empty() {return r==l-1;}
    inline int size(){return (r-l+1>=0) ? r-l+1:r-l+1+sz;}
    inline int begin(){return l;}
    inline int end(){return r;}
    inline H& front(){return deqe[l];}
    inline H& back(){return deqe[r];}
    inline void push_front(const H &x){l=(l>=1)?l-1:sz-1;deqe[l]=x;}
    inline void push_back(const H &x) {r=(r==sz-1)?0:r+1;deqe[r]=x;}
    inline void pop_front() {if (!empty()) l=(l==sz-1)?0:l+1;}
    inline void pop_back(){if (!empty()) r=(r>=1)?r-1:sz-1;}
    inline void clear() {l=r+1;}
    inline void out(){if (!empty()) {int i=l;while(i!=r){cout<<deqe[i]<<' ';i=(i+1)%sz;}cout<<deqe[i]<<'\n';}}
};