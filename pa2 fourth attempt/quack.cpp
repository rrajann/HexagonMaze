/**
 * @file quack.cpp
 * Implementation of the Quack class.
 *
 */

template <class T>
Quack<T>::Quack() {
    n1 = 0;
    n2 = -1;
}

/**
 * Adds the parameter object to the right of the Quack.
 *
 * @param newItem object to be added to the Quack.
 */
template <class T>
void Quack<T>::pushR(T newItem) {
    if (n2 + 1 == data.size()) {
        data.push_back(newItem);
    } else { 
        data[n2 + 1] = newItem;
    }
    n2++;
}

/**
 * Removes the object at the left of the Quack, and returns it to the
 * caller.
 *
 * See .h file for implementation notes.
 *
 * @return The item that used to be at the left of the Quack.
 */
template <class T>
T Quack<T>::popL() {
    T l = data[n1];
    n1++;

    if (n2 >= (n2 - n1 + 1) * 2) {

        vector<T> shift;

        for (int i = n1; i <= n2; i++) {
            shift.push_back(data[i]);
        }

        data = shift;
        n2 = n2 - n1;
        n1 = 0;
    } 

    return l;
}
/**
 * Removes the object at the right of the Quack, and returns it to the
 * caller.
 *
 * @return The item that used to be at the right of the Quack.
 */
template <class T>
T Quack<T>::popR() {

    T removed = data[n2];
    n2--;

    if (n2 >= (n2 - n1 + 1) * 2) {
        vector<T> shift;
        
        for (int i = n1; i <= n2; i++) {
            shift.push_back(data[i]);
        }

        data = shift;
        n2 = (n2 - n1 + 1) - 1;
        n1 = 0;
    }

    return removed;
}

/**
 * Finds the object at the left of the Quack, and returns it to the
 * caller. Unlike popL(), this operation does not alter the quack.
 *
 * @return The item at the front of the quack.
 */
template <class T>
T Quack<T>::peekL() {
    /**
     * @todo Your code here! You will need to replace the following line.
     */
    return data[n1];
}

/**
 * Finds the object at the right of the Quack, and returns it to the
 * caller. Unlike popR(), this operation does not alter the quack.
 *
 * @return the value of The item at the right of the quack.
 */
template <class T>
T Quack<T>::peekR() {
    /**
     * @todo Your code here! You will need to replace the following line.
     */
    return data[n2];
}

/**
 * Determines if the Quack is empty.
 *
 * @return bool which is true if the Quack is empty, false otherwise.
 */
template <class T>
bool Quack<T>::isEmpty() const {
    /**
     * @todo Your code here! You will need to replace the following line.
     */
    return (n2 - n1 == -1);
}

