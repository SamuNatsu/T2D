#ifndef T2D_TRIGGER_BOX_HPP_INCLUDED_
#define T2D_TRIGGER_BOX_HPP_INCLUDED_


// Headers
#include "./Header.hpp"
#include "./GameObject.hpp"
#include "./RigidBox.hpp"

T2D_NS_BEGIN

// Abstract trigger collider
class T2D_API TriggerBox: public RigidBox {
public:
    TriggerBox();
    TriggerBox(const TriggerBox&) = delete;
    TriggerBox(TriggerBox&&) = delete;
    virtual ~TriggerBox() = default;

    TriggerBox& operator=(const TriggerBox&) = delete;
    TriggerBox& operator=(TriggerBox&&) = delete;

    void test(const std::weak_ptr<GameObject>&);
    void update();

    virtual void onEnter(GameObject&);
    virtual void onTrigger(GameObject&);
    virtual void onExit(GameObject&);

protected:
    int m_Flag;
    std::unordered_map<size_t, std::weak_ptr<GameObject>> m_ActiveObj[2];

};

T2D_NS_END


#endif // T2D_TRIGGER_BOX_HPP_INCLUDED_
