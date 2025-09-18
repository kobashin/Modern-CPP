template <typename Traits>
class unique_handle {
    using pointer = typename Traits::pointer;
    pointer m_value;

    public:
        unique_handle(unique_handle const&) = delete;
        unique_handle& operator=(unique_handle const&) = delete;
        explicit unique_handle(pointer value = Traits::invalid()) noexcept : m_value(value){}
        unique_handle(unique_handle&& other) noexcept : m_value{other.release()}
        unique_handle& operator=(unique_handle&& other) noexcept {
            if(this != &other) {
                reset(other.release());
                return *this;
            }
        }
        ~unique_handle() noexcept {Traits::close(m_value);}
        explicit operator bool() const noexcept {return m_value != Traits::invalid();}
        pointer get() const noexcept {return m_value;}
        pointer release() noexcept {
            auto value = m_value;
            m_value = Traits::invalid();
            return value;
        }
        bool reset(pointer value = Traits::invalid()) noexcept {
            if (m_value != value) {
                Traits::close(m_value);
                m_value = value;
            }
            return static_cast<bool>(*this);
        }
        void swap(unique_handle<Traits> & other) noexcept {
            std::swap(m_value, other.m_value);
        }
}