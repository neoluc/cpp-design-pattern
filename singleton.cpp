
class Dog {
	static Dog *dog;
	Dog() {
		dog = nullptr;
	}
	~Dog() {
		delete dog;
	}
public:
	static Dog *get_instance() {
		if (dog == nullptr) {
			dog = new Dog();
		}
		return dog;
	}
};

int main() {
	Dog *dog = Dog.get_instance();
}