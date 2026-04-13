import socket

def security_audit():
    # Requirement: Take target IP as input [cite: 172]
    target = input("Enter Target IP for Security Audit: ")
    ports = {21: "FTP", 22: "SSH", 80: "HTTP", 443: "HTTPS"} # [cite: 174]
    
    # Simple vulnerability database [cite: 178]
    vuln_db = {
        "FTP": "Potential for cleartext credential sniffing.",
        "SSH": "Check for outdated versions or weak passwords.",
        "HTTP": "Check for XSS or SQL injection vulnerabilities.",
        "HTTPS": "Ensure modern TLS versions are in use."
    }

    report_content = f"<h1>Security Audit Report: {target}</h1><table border='1'><tr><th>Port</th><th>Service</th><th>Vulnerability Note</th></tr>"
    
    print(f"Starting audit on {target}...")
    
    for port, service in ports.items():
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.settimeout(1)
        # Requirement: Perform port scan [cite: 174]
        result = s.connect_ex((target, port))
        
        if result == 0:
            # Requirement: Identify service and check vulnerabilities [cite: 176, 178]
            vuln = vuln_db.get(service, "No specific info.")
            report_content += f"<tr><td>{port}</td><td>{service} (OPEN)</td><td>{vuln}</td></tr>"
            print(f"Port {port} ({service}): OPEN")
        s.close()
    
    report_content += "</table>"
    
    # Requirement: Generate HTML report [cite: 179]
    with open("sample_report.html", "w") as f:
        f.write(report_content)
    
    print("\nAudit finished! Open 'sample_report.html' to see results.")

if __name__ == "__main__":
    security_audit()