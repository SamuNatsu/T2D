#include "TriggerBox.hpp"

T2D_NS_BEGIN

TriggerBox::TriggerBox(): m_Flag(0) {}

void TriggerBox::test(const std::weak_ptr<GameObject>& _o) {
    auto ptr = _o.lock();
    if (collide(ptr->rigid))
        m_ActiveObj[m_Flag].emplace(ptr->UUID, _o);
}

void TriggerBox::update() {
    int lst = m_Flag ^ 1;
    for (auto &i : m_ActiveObj[m_Flag]) {
        auto ptr = i.second.lock();
        if (m_ActiveObj[lst].count(i.first)) 
            m_ActiveObj[lst].erase(i.first);
        else 
            onEnter(*ptr);
        onTrigger(*ptr);
    }
    m_Flag ^= 1;
    for (auto &i : m_ActiveObj[m_Flag]) {
        auto ptr = i.second.lock();
        onExit(*ptr);
    }
    m_ActiveObj[m_Flag].clear();
}

void TriggerBox::onEnter(GameObject& _o) {}

void TriggerBox::onTrigger(GameObject& _o) {}

void TriggerBox::onExit(GameObject& _o) {}


T2D_NS_END
