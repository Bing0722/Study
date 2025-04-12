#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H

#include <iostream>
#include <unordered_map>

/**
 * 享元设计模式
 *
 * 意图：通过在多个对象之间共享状态的公共部分，而不是在每个对象中保留所有数据，
 *       从而让更多对象适配可用的内存。
 */
struct SharedState {
  std::string brand_;
  std::string model_;
  std::string color_;

  SharedState(const std::string &brand, const std::string &model,
              const std::string &color)
      : brand_(brand), model_(model), color_(color) {}

  friend std::ostream &operator<<(std::ostream &os, const SharedState &ss) {
    return os << "[ " << ss.brand_ << " , " << ss.model_ << " , " << ss.color_
              << " ]";
  }
};

struct UniqueState {
  std::string owner_;
  std::string plates_;

  UniqueState(const std::string &owner, const std::string &plates)
      : owner_(owner), plates_(plates) {}

  friend std::ostream &operator<<(std::ostream &os, const UniqueState &us) {
    return os << "[ " << us.owner_ << " , " << us.plates_ << " ]";
  }
};

/**
 * 享元存储属于多个实际业务实体的公共部分状态（也称为内部状态）。
 * 享元通过其方法参数接受其余的状态（每个实体独有的外部状态）。
 */
class Flyweight {
private:
  SharedState *shared_state_;

public:
  Flyweight(const SharedState *shared_state)
      : shared_state_(new SharedState(*shared_state)) {}

  Flyweight(const Flyweight &other)
      : shared_state_(new SharedState(*other.shared_state_)) {}

  ~Flyweight() { delete shared_state_; }

  SharedState *shared_state() const { return shared_state_; }

  void Operation(const UniqueState &unique_state) const {
    std::cout << "Flyweight: Displaying shared (" << *shared_state_
              << ") and unique (" << unique_state << ") state.\n";
  }
};
/**
 * 享元工厂创建和管理享元对象。它确保享元被正确共享。
 * 当客户端请求一个享元时，工厂返回一个现有实例或创建一个新的实例（如果尚不存在）。
 */
class FlyweightFactory {

private:
  std::unordered_map<std::string, Flyweight> flyweights_;

  /**
   * 返回给定状态的享元的字符串哈希值。
   */
  std::string GetKey(const SharedState &ss) const {
    return ss.brand_ + "_" + ss.model_ + "_" + ss.color_;
  }

public:
  FlyweightFactory(std::initializer_list<SharedState> share_states) {
    for (const SharedState &ss : share_states) {
      this->flyweights_.insert(
          std::make_pair(this->GetKey(ss), Flyweight(&ss)));
    }
  }

  /**
   * 返回具有给定状态的现有享元或创建一个新享元。
   */
  Flyweight GetFlyweight(const SharedState &shared_state) {
    std::string key = this->GetKey(shared_state);
    if (this->flyweights_.find(key) == this->flyweights_.end()) {
      std::cout
          << "FlyweightFactory: Can't find a flyweight, creating new one.\n";
      this->flyweights_.insert(std::make_pair(key, Flyweight(&shared_state)));
    } else {
      std::cout << "FlyweightFactory: Reusing existing flyweight.\n";
    }
    return this->flyweights_.at(key);
  }

  void ListFlyweights() const {
    size_t count = this->flyweights_.size();
    std::cout << "\nFlyweightFactory: " << count << " flyweights:\n";
    for (std::pair<std::string, Flyweight> pair : this->flyweights_) {
      std::cout << pair.first << "\n";
    }
  }
};

inline void
AddCarToPoliceDatabase(FlyweightFactory &ff, const std::string &plates,
                       const std::string &owner, const std::string &brand,
                       const std::string &model, const std::string &color) {
  std::cout << "\nClient: Adding a car to database.\n";
  const Flyweight &flyweight = ff.GetFlyweight({brand, model, color});
  flyweight.Operation({owner, plates});
}

#endif // FLYWEIGHT_H
