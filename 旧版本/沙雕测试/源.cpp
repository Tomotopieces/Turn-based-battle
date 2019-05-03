class A;
class B;
class A :public B
{
};

class B :public A
{
};

int main() {
	return 0;
}