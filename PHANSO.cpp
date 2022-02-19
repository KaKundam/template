struct PS
{
	lo t,m;
	PS() {t=0;m=1;}
	friend void read(PS &a) {cin>>a.t;if (cin>>a.m);else a.m=1;}
	friend void prinf(const PS &a,char c=' ') {cout<<a.t<<c<<a.m<<'\n';}
	PS(const lo u,const lo v) {
		this->t=u;
		this->m=v;
		lo g=__gcd(t,m);
		if (this->t<0) t=-t,m=-m;
		this->t=t/g;
		this->m=m/g;
	}
	PS(const lo u){
		this->t=u;
		this->m=1;
	}
	PS inv(){
		return PS(this->m,this->t);
	}
	/// so sánh
	inline bool operator <  (const PS &a) const{return t*a.m<m*a.t;}
	inline bool operator == (const PS &a) const{return t*a.m==m*a.t;}
	inline bool operator >  (const PS &a) const{return t*a.m>m*a.t;}
	inline bool operator >= (const PS &a) const{return a<*this;}
	inline bool operator <= (const PS &a) const{return a>*this;}
	inline bool operator != (const PS &a) const{return !(a==*this);}
	// phép toán
	inline PS operator + (const PS &a) {return PS(t*a.m+a.t*m,m*a.m);}
	inline PS operator + (const lo sn) {return (*this+PS(sn));}
	inline friend PS operator + (lo sn,PS &a) {return a+sn;}
	inline PS operator - (const PS &a) {return PS(t*a.m-a.t*m,m*a.m);}
	inline PS operator - (const lo sn) {return (*this-PS(sn));}
	inline friend PS operator - (lo sn,PS &a) {return PS(sn*a.m-a.t,a.m);}
	inline PS operator * (const PS &a) {return PS(t*a.t,m*a.m);}
	inline PS operator * (const lo sn) {return PS(t*sn,m);}
	inline friend PS operator * (lo sn,PS &a) {return a*sn;}
	inline PS operator / (/***/ PS &a) {return ((*this)*a.inv());}
	inline PS operator / (const lo sn) {return PS(t,m*sn);}
	inline friend PS operator / (lo sn,PS &a) {return a.inv()*sn;}
};