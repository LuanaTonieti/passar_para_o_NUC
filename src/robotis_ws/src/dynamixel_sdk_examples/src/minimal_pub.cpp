// Open terminal #2 
// $ ros2 run dynamixel_sdk_examples minimal_pub
// $ ros2 launch dynamixel_sdk_examples dynamixel_sdk_examples.launch.py

#include <chrono>
#include <memory>
#include <thread>
#include <functional>
#include <unistd.h>

#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/msg/set_position.hpp"
#include "custom_interfaces/msg/set_position_original.hpp"
using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher()
  : Node("minimal_publisher")
  {
    RCLCPP_INFO(this->get_logger(), "Run read minimal publisher");
    publisher_ = this->create_publisher<custom_interfaces::msg::SetPosition>("set_position", 10); 
    publisher_single = this->create_publisher<custom_interfaces::msg::SetPositionOriginal>("set_position_single", 10);
    timer_ = this->create_wall_timer(
      500ms, std::bind(&MinimalPublisher::timer_callback, this));
  }

private:
  void timer_callback()
  {
    auto message = custom_interfaces::msg::SetPosition();   
    auto message_single = custom_interfaces::msg::SetPositionOriginal(); 
    RCLCPP_INFO(this->get_logger(), "Stand Up Back");
            message_single.id = 254;
            message_single.address = 112;
            message_single.position = 60; 
            //era 60
            publisher_single->publish(message_single);
            
            //Posição inicial:
            RCLCPP_INFO(this->get_logger(), "Step 1");
            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
            //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18  19 
            message.position = {1724,2367,2294,1812,627,3468,2052,2044,2032,2106,1712,2384,2791,1306,2536,1560,2048,2081,2047,2047};
            publisher_->publish(message);
            usleep(5000000);

            //Posição inicial:
            RCLCPP_INFO(this->get_logger(), "Step 1.5");
            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
            //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18  19 
            message.position = {1724,2367,2294,1812,627,3468,2052,2044,2032,2106,1712,2384,2791,1306,2536,1560,2048,2081,2047,2047};
            publisher_->publish(message);
            usleep(2000000);
            
            //Se preparando para equilibrar em uma perna:
            RCLCPP_INFO(this->get_logger(), "Step 2");
            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19, 20};
            //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18  19    20
            message.position = {2047,2047,2692,1976,2046,2046,2047,2047,2040,2164,1733,2368,2398,1654,2187,1882,2152,2191,2047,2047};
            publisher_->publish(message);
            usleep(2000000);

            //Equilibrando em uma perna:
            //arrumar o pé esquerdo
            RCLCPP_INFO(this->get_logger(), "Step 3");
            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19, 20};
            //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19   20
            message.position = {2047,2047,2648,1957,1240,3598,2047,2047,2040,2144,1726,2634,2398,1329,2238,1823,2152,1974,2047,2047};   
            publisher_->publish(message);
            usleep(2000000);

            //Abrindo as pernas:
            RCLCPP_INFO(this->get_logger(), "Step 4");
            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19, 20};
            //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19   20
            message.position = {2047,2047,2648,1957,1240,3598,2047,2047,2040,2397,1726,2403,2398,1615,2238,1823,2152,2084,2047,2047};   
            publisher_->publish(message);
            usleep(2000000);

            //Estabilizando:
            RCLCPP_INFO(this->get_logger(), "Step 5");
            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19, 20};
            //                    1   2     3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19   20
            message.position = {1724,2367,2294,1812,627,3598,2047,2047,2040,2397,1803,2282,2420,1615,2238,1812,2097,2106,2047,2047};   
            publisher_->publish(message);
            usleep(2000000);

            message_single.id = 13;
            message_single.address = 112;
            message_single.position = 120;
            publisher_single->publish(message_single);
            
            message_single.id = 14;
            message_single.address = 112;
            message_single.position = 120;
            publisher_single->publish(message_single);
            usleep(1000000);

            //Abrindo os braços:     
            RCLCPP_INFO(this->get_logger(), "Step 6");
            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
            //                    1    2    3    4   5    6    7    8    9   10   11   12   13   14   15   16   17   18   19    20
            message.position = {2241,1894,2427,1702,2019,2102,2052,2044,1814,2397,1803,2381,2420,1615,2282,1856,2097,2106,2047,2047};
            publisher_->publish(message);
            usleep(2000000);

            //Descendo:
            RCLCPP_INFO(this->get_logger(), "Step 7");
            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
            //                    1    2    3    4   5    6    7    8    9   10   11   12   13   14   15   16   17   18   19    20
            message.position = {2241,1894,2427,1702,2019,2102,2052,2044,1814,2397,1449,2780,3506,492,2850,1275,1716,2288,2047,2047};
            publisher_->publish(message);
            usleep(1500000);

            //Ajustando agachado:
            RCLCPP_INFO(this->get_logger(), "Step 8");
            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
            //                    1    2    3    4   5    6    7    8    9   10   11   12   13   14   15   16   17   18   19    20
            message.position = {2241,1894,2427,1702,2019,2102,2052,2044,1814,2397,1141,3000,3693,492,2883,1231,1716,2288,2047,2047};
            publisher_->publish(message);
            usleep(4000000);

            //Subindo:
            RCLCPP_INFO(this->get_logger(), "Step 9");
            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
            //                    1    2    3    4   5    6    7    8    9   10   11   12   13   14   15   16   17   18   19    20
            message.position = {2241,1894,2427,1702,2019,2102,2052,2044,1814,2397,1726,2425,2791,1306,2524,1625,2097,2106,2047,2047};
            publisher_->publish(message);
            usleep(4000000);

            //Estendendo a perna esquerda:
            //RCLCPP_INFO(this->get_logger(), "Step 10");
            //message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
            //                    1    2    3    4   5    6    7    8    9   10   11   12   13   14   15   16   17   18   19    20
            //message.position = {2241,1894,2427,1702,2019,2102,2052,2044,1814,2397,1726,2425,2791,1339,2524,1625,2097,2106,2047,2047};
            //publisher_->publish(message);
            //usleep(2400000);

            //Estendendo totalmente a perna esquerda:
            //RCLCPP_INFO(this->get_logger(), "Step 11");
            //message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
            //                    1    2    3    4   5    6    7    8    9   10   11   12   13   14   15   16   17   18   19    20
            //message.position = {2241,1894,2427,1702,2019,2102,2052,2044,1814,2397,1726,2172,2791,1669,2524,1790,2097,2106,2047,2047};
            //publisher_->publish(message);
            //usleep(2400000);

            //Estendendo totalmente a perna esquerda e jogando um pouco pra direita:
            ///RCLCPP_INFO(this->get_logger(), "Step 12");
            //message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
            //                    1    2    3    4   5    6    7    8    9   10   11   12   13   14   15   16   17   18   19    20
            //message.position = {2241,1894,2427,1702,2019,2102,2052,2044,1880,2287,1726,2084,2791,1922,2524,1922,2097,2106,2047,2047};
            //publisher_->publish(message);
            //usleep(2400000);

            //Pré-subida:
            //RCLCPP_INFO(this->get_logger(), "Step 13");
            //message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
            //                    1    2    3    4   5    6    7    8    9   10   11   12   13   14   15   16   17   18   19    20
            //message.position = {2241,1894,2427,1702,2019,2102,2052,2044,1880,2287,1715,2084,2791,1922,2524,1922,2097,2106,2047,2047};
            //publisher_->publish(message);
            //usleep(2400000);

            //Subida:
            //RCLCPP_INFO(this->get_logger(), "Step 13.5");
            //message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
            //                    1    2    3    4   5    6    7    8    9   10   11   12   13   14   15   16   17   18   19    20
            //message.position = {2241,1894,2427,1702,2019,2102,2052,2044,1891,2462,1726,2084,2791,1922,2524,1922,2097,2106,2047,2047};
            //publisher_->publish(message);
            //usleep(2400000);

            //Dobrando os joelhos da perna direita para a subida:
            //arrumar
            RCLCPP_INFO(this->get_logger(), "Step 10");
            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
            //                    1    2    3    4   5    6    7    8    9   10   11   12   13   14   15   16   17   18   19    20
            message.position = {2241,1894,2427,1702,2019,2102,2052,2044,1922,2462,1341,2260,2879,1922,2381,1922,2097,2106,2047,2047};
            publisher_->publish(message);
            usleep(2400000);

            //Dobrando os joelhos da perna direita para a subida:
            //RCLCPP_INFO(this->get_logger(), "Step 15");
            //message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
            //                    1    2    3    4   5    6    7    8    9   10   11   12   13   14   15   16   17   18   19    20
            //message.position = {2241,1894,2427,1702,2019,2102,2052,2044,1979,2353,1616,2084,2879,1922,2304,1922,2097,2106,2047,2047};
            //publisher_->publish(message);
            //usleep(2400000);

            //esticando a direita para a subida:
            RCLCPP_INFO(this->get_logger(), "Step 11");
            message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
            //                    1    2    3    4   5    6    7    8    9   10   11   12   13   14   15   16   17   18   19    20
            message.position = {2241,1894,2427,1702,2019,2102,2052,2044,1979,2353,1715,2392,2626,1592,2282,1922,2174,2106,2047,2047};
            publisher_->publish(message);
            usleep(2400000);


            //Pré-subida (esticando a perna direita):
            //RCLCPP_INFO(this->get_logger(), "Step 13.5");
            //message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
            //                    1    2    3    4   5    6    7    8    9   10   11   12   13   14   15   16   17   18   19    20
            //message.position = {2241,1894,2427,1702,2019,2102,2052,2044,1803,2275,1880,2084,2494,1922,2315,1922,2097,2106,2047,2047};
            //publisher_->publish(message);
            //usleep(2400000);


            //Fechando os pés:
            //RCLCPP_INFO(this->get_logger(), "Step 7");
            //message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
            //                    1   2     3    4   5    6    7    8    9   10   11   12   13   14   15   16   17   18   19  20
            //message.position = {1724,2367,2294,1812,627,3468,2052,2044,1715,1770,1405,2615,2967,1350,2495,1810,1716,2235,2047,2047};  
            //publisher_->publish(message);
            //usleep(2400000);
            //RCLCPP_INFO(this->get_logger(), "Step 6");
            //message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
            //                    1   2     3    4   5    6    7    8    9   10   11   12   13   14   15   16   17   18   19  20
            //message.position = {1724,2367,2294,1812,627,3468,2052,2044,1715,1902,1680,2549,2791,1306,2495,1634,2048,2059,2047,2047};  
            //publisher_->publish(message);
            //usleep(2400000);
            //Se estabilizando:
            //RCLCPP_INFO(this->get_logger(), "Step 3");
            //message.id = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
            //                    1    2    3    4   5    6    7    8    9   10   11   12   13   14   15   16   17   18   19    20
            //message.position = {1724,2367,2294,1812,627,3468,2052,2044,1768,2106,1571,2428,2791,1306,2440,1634,1861,2081,2047,2047};
            //publisher_->publish(message);
            //usleep(2400000);

  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<custom_interfaces::msg::SetPosition>::SharedPtr publisher_;     
  rclcpp::Publisher<custom_interfaces::msg::SetPositionOriginal>::SharedPtr publisher_single; 
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}