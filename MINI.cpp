template <typename H,typename Hu> inline bool mini(H &a,Hu b)
{
	return (a>b) ? a=b,1:0;
}