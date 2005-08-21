class wxBogus
{
public:
	virtual void virt2() { printf("C++ virt2\n"); }
	void nonvirt1() { printf("C++ nonvirt1\n"); virt2(); }
	virtual void virt1() { printf("C++ virt1\n"); nonvirt1(); }
};
