int main() {
    constexpr bool someCondition = false;

    // Impossible to use const/constexpr
    int a{};
    if (someCondition) {
        a = 30;
    } else {
        a = 20;
    }

    // Supports const/constexpr
    constexpr int b{(someCondition) ? 30 : 20};
}
