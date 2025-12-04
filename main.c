    // 弱點 2: 使用不安全的 strcpy - 沒有邊界檢查
    strcpy(ssid, input_ssid); 
    printf("Connecting to WiFi: %s\n", ssid);
}

// 弱點 3: Hardcoded Credentials (硬編碼憑證)
void check_admin() { 
    char *password = "admin123";  // Security Hotspot
    char *api_key = "sk-1234567890abcdefghijklmnop";  // 另一個硬編碼密鑰
    
    if (strcmp(password, "admin123") == 0) {
        printf("Admin Login Success!\n");
        printf("API Key: %s\n", api_key);
    }
}

// 弱點 4: 使用極度危險的 gets() 函數
void unsafe_input() {
    char buffer[50];
    printf("Enter your name: ");
    gets(buffer);  // 極度危險！沒有任何邊界檢查，已被 C11 標準移除
    printf("Hello, %s\n", buffer);
}

// 弱點 5: sprintf 沒有邊界檢查
void format_string_vuln(char *user_input) {
    char output[20];
    sprintf(output, "User: %s", user_input);  // 危險！應該用 snprintf
    printf("%s\n", output);
}

int main() {
    printf("IoT Device Starting...\n");
    check_admin();
    
    // 觸發 Buffer Overflow
    connect_wifi("SuperLongWiFiNameThatWillDefinitelyCrashTheSystem");
    
    // 觸發 gets() 危險函數警告
    // unsafe_input();  // 註解掉避免編譯時就失敗
    
    // 觸發 sprintf 問題
    format_string_vuln("VeryLongUserInputThatExceedsBuffer");
    
    return 0;
}