#ifndef ITERATOR_H
#define ITERATOR_H

/**
 * 迭代器设计模式
 *
 * 意图：允许您遍历集合的元素，而无需暴露其底层表示（列表、堆栈、树等）。
 */

#include <iostream>
#include <string>
#include <vector>

/**
 * C++ 自带迭代器实现，适用于标准库中定义的各种泛型容器。
 */

template <typename T, typename U> class Iterator {
public:
  typedef typename std::vector<T>::iterator iter_type;
  Iterator(U *p_data, bool reverse = false) : m_p_data_(p_data) {
    m_it_ = m_p_data_->m_data_.begin();
  }

  void First() { m_it_ = m_p_data_->m_data_.begin(); }

  void Next() { m_it_++; }

  bool IsDone() { return (m_it_ == m_p_data_->m_data_.end()); }

  iter_type Current() { return m_it_; }

private:
  U *m_p_data_;
  iter_type m_it_;
};

/**
 * 泛型集合/容器提供一个或多个方法，用于检索与集合类兼容的新迭代器实例。
 */

template <class T> class Container {
  friend class Iterator<T, Container>;

public:
  void Add(T a) { m_data_.push_back(a); }

  Iterator<T, Container> *CreateIterator() {
    return new Iterator<T, Container>(this);
  }

private:
  std::vector<T> m_data_;
};

class Data {
public:
  Data(int a = 0) : m_data_(a) {}

  void set_data(int a) { m_data_ = a; }

  int data() { return m_data_; }

private:
  int m_data_;
};

#endif // ITERATOR_H
