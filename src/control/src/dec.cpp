// Open terminal #2 
// $ ros2 run dynamixel_sdk_examples minimal_pub
// $ ros2 run control decision
#include <chrono>
#include <memory>
#include <thread>
#include <functional>
#include <unistd.h>

#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/msg/decision.hpp"

using namespace std::chrono_literals;

class DecisionNode : public rclcpp::Node
{
public:
  DecisionNode()
  : Node("decision")
  {
    RCLCPP_INFO(this->get_logger(), "Run decision publisher");
    publisher_ = this->create_publisher<custom_interfaces::msg::Decision>("/decision", 10); 
    timer_ = this->create_wall_timer(
      50ms, std::bind(&DecisionNode::timer_callback, this));
  }

private:
  void executeTest(){
    auto message = custom_interfaces::msg::Decision();
    // PARADO  
    RCLCPP_INFO(this->get_logger(), "PARADO");
    message.decision = 1;          
    publisher_->publish(message);
    sleep(12); 
    // GREETING
    RCLCPP_INFO(this->get_logger(), "GREETING");
    message.decision = 2;          
    publisher_->publish(message);
    sleep(8);  
    // RIGHT KICK
    RCLCPP_INFO(this->get_logger(), "RIGHT KICK");
    message.decision = 3;          
    publisher_->publish(message);
    sleep(8);  
    // LEFT KICK
    message.decision = 4;    
    RCLCPP_INFO(this->get_logger(), "LEFT KICK"); 
    publisher_->publish(message);
    sleep(8);
    // TURN RIGHT  
    message.decision = 5;   
    RCLCPP_INFO(this->get_logger(), "TURN RIGHT");       
    publisher_->publish(message);
    sleep(8); 
    // TURN LEFT 
    message.decision = 6;    
    RCLCPP_INFO(this->get_logger(), "TURN LEFT");    
    publisher_->publish(message);
    sleep(8); 
    // GOODBYE 
    RCLCPP_INFO(this->get_logger(), "GOODBYE");
    message.decision = 7;          
    publisher_->publish(message);
    sleep(8);  
    // SEARCH BALL
    message.decision = 8;      
    RCLCPP_INFO(this->get_logger(), "SEARCH BALL");    
    publisher_->publish(message);
    sleep(8);  
    // TURN BALL CLOCKWISE
    message.decision = 9;       
    RCLCPP_INFO(this->get_logger(), "TURN BALL CLOCKWISE");   
    publisher_->publish(message);
    sleep(8);  
    // TURN BALL ANTICLOCKWISE
    message.decision = 10;         
    RCLCPP_INFO(this->get_logger(), "TURN BALL ANTICLOCKWISE"); 
    publisher_->publish(message);
    sleep(8);  
    // FALL LEFT
    message.decision = 11;   
    RCLCPP_INFO(this->get_logger(), "FALL LEFT");
    publisher_->publish(message);
    sleep(8); 
    // FALL RIGHT 
    message.decision = 12;   
    RCLCPP_INFO(this->get_logger(), "FALL RIGHT");       
    publisher_->publish(message);
    sleep(8);  
    // AGACHANDO
    message.decision = 13;     
    RCLCPP_INFO(this->get_logger(), "CROUCH");
    publisher_->publish(message);
    sleep(8);  
    // WALKING
    message.decision = 14;         
    RCLCPP_INFO(this->get_logger(), "WALKING"); 
    publisher_->publish(message);
    sleep(8);  
    // GAIT
    message.decision = 15;    
    RCLCPP_INFO(this->get_logger(), "GAIT");  
    publisher_->publish(message);
    sleep(8);  
    // STAND UP BACK
    message.decision = 16;        
    RCLCPP_INFO(this->get_logger(), "STAND UP BACK"); 
    publisher_->publish(message);
    sleep(8);  
    // STAND UP FRONT
    message.decision = 17;    
    RCLCPP_INFO(this->get_logger(), "STAND UP FRONT");      
    publisher_->publish(message);
    sleep(8);  
    // ANDAR ESQUERDA
    message.decision = 18;   
    RCLCPP_INFO(this->get_logger(), "WALK LEFT"); 
    publisher_->publish(message);
    sleep(8); 
    // ANDAR DIREITA 
    message.decision = 19;     
    RCLCPP_INFO(this->get_logger(), "WALK RIGHT");     
    publisher_->publish(message);
    sleep(8);
  }

  void timer_callback()
  {
    executeTest();
    
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<custom_interfaces::msg::Decision>::SharedPtr publisher_;     
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<DecisionNode>());
  rclcpp::shutdown();
  return 0;
}