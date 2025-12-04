#include <stdio.h>
#include <string.h>

// 模擬 IoT 設備的連接功能
void connect_wifi(char *input_ssid) {
    char ssid[10]; // 弱點 1: 緩衝區太小，容易 Buffer Overflow
    
    // 弱點 2: 使用不安全的 strcpy
    strcpy(ssid, input_ssid); 
    printf("Connecting to WiFi: %s\n", ssid);
}

void check_admin() {
    // 弱點 3: Hardcoded Credentials (硬編碼憑證) -> 這是 Security Hotspot 重點
    char *password = "123456"; 
    
    if (strcmp(password, "123456") == 0) {
        printf("Admin Login Success!\n");
    }
}

int main() {
    printf("IoT Device Starting...\n");
    check_admin();
    
    // 模擬接收外部過長的輸入
    connect_wifi("SuperLongWiFiNameThatWillCrashTheSystem"); 
    
    return 0;
}