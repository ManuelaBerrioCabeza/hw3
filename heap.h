#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator()): m_(m), comp_(c){};

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  int m_;
  std::vector<T> heap_;
  PComparator comp_;
  void heapifyDown(size_t i);
  void heapifyUp(size_t i);

};

// Add implementation of member functions here

//push
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  heap_.push_back(item);
  heapifyUp(heap_.size()-1);

}

//top
// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap_.front();
}


//pop
// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  std::swap(heap_.front(), heap_.back());
  heap_.pop_back();
  heapifyDown(0);
}

//empty
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return heap_.empty();

}

//size
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return heap_.size();
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {
    heap_.clear();
}

//heapifyUp
template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifyUp(size_t i)
{
  if (i == 0){
    return; } 

  size_t parentIndex = (i - 1) / m_;

  if (comp_(heap_[i], heap_[parentIndex])) {
    std::swap(heap_[i], heap_[parentIndex]);
    heapifyUp(parentIndex);  
  }

}

//heapifyDown
template <typename T, typename PComparator>
void Heap<T,PComparator>::heapifyDown(size_t i)
{
  size_t bestIndex = i;  
    
    for (int j = 1; j <= m_; ++j) {
        size_t childIndex = m_ * i + j;
        if (childIndex < heap_.size() && comp_(heap_[childIndex], heap_[bestIndex])) {
            bestIndex = childIndex;  
        }
    }

    
    if (bestIndex != i) {
        std::swap(heap_[i], heap_[bestIndex]);
        heapifyDown(bestIndex);
    }

}



#endif

