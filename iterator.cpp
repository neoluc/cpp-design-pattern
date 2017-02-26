template <class T>
class Iterator {
public:
	virtual bool has_next() = 0;
	virtual T next() = 0;
};

class Dog {

};

class DogIterator : public Iterator<Dog> {
	vector<Dog> dogs;
	int position;
public:
	DogIterator(vector<Dog> dogs) {
		this->dogs = dogs;
		position = 0;
	}
	virtual bool has_next() {
		if (position >= dogs.size()) {
			return false;
		}
		return true;
	}
	virtual Dog next() {
		Dog t = dogs[position];
		position++;
		return t;
	}
};

int main() {
	vector<Dog> dogs;
	DogIterator dog_iterator(dogs);
	while (dog_iterator.has_next()) {
		Dog dog = dog_iterator.next();
	}
}