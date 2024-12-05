## 1、获取 MAC 地址
```c++
bool RemoteServerConnection::getMacAddress(const std::string& ip, std::string& mac_address) {

  struct ifaddrs* ifaddr;
  struct ifaddrs* ifa;
  int family;
  char host[NI_MAXHOST] = {0}, mac[18] = {0};

  if (getifaddrs(&ifaddr) == -1) {
      perror("getifaddrs");
      return false;
  }

  for (ifa = ifaddr; ifa != nullptr; ifa = ifa->ifa_next) {                     // 遍历所有的网络接口
      family = ifa->ifa_addr->sa_family;
      if (family == AF_INET) {                                                  // 如果接口是IPv4类型
          
          if (getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host,
              NI_MAXHOST, nullptr, 0, NI_NUMERICHOST) == 0) {                   // 获取IP地址
              if (ip == host) {                                                 // 找到了对应IP的接口，获取MAC地址
                  struct ifreq ifr;
                  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
                  if (sockfd == -1) {
                      perror("socket");
                      return false;
                  }

                  strncpy(ifr.ifr_name, ifa->ifa_name, IFNAMSIZ - 1);
                  if (ioctl(sockfd, SIOCGIFHWADDR, &ifr) == -1) {
                      perror("ioctl");
                      close(sockfd);
                      return false;
                  }

                  unsigned char* mac_ptr = reinterpret_cast<unsigned char*>(ifr.ifr_hwaddr.sa_data);
                  snprintf(mac, sizeof(mac), "%02x:%02x:%02x:%02x:%02x:%02x",
                              mac_ptr[0], mac_ptr[1], mac_ptr[2],
                              mac_ptr[3], mac_ptr[4], mac_ptr[5]);

                  mac_address = mac;
                  close(sockfd);
                  freeifaddrs(ifaddr);
                  return true;
              }
          }
      }
  }

  freeifaddrs(ifaddr);
  return false;

}
```
