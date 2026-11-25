# DNS Configuration for dyrakarmy.eu

## GitHub Pages Custom Domain Setup

### Required DNS Records

#### A Records (for GitHub Pages):
```
Type: A
Name: @
Value: 185.199.108.153
TTL: Auto

Type: A
Name: @
Value: 185.199.109.153
TTL: Auto

Type: A
Name: @
Value: 185.199.110.153
TTL: Auto

Type: A
Name: @
Value: 185.199.111.153
TTL: Auto
```

#### CNAME Record:
```
Type: CNAME
Name: www
Value: biramentv-ux.github.io
TTL: Auto
```

### Alternative: Using GitHub DNS (Recommended)

1. Go to your domain registrar
2. Add a CNAME record:
   - Name: www
   - Value: biramentv-ux.github.io

3. Add A records:
   - Name: @
   - Value: 185.199.108.153 (and other GitHub IPs)

### GitHub Repository Settings

1. Go to Repository Settings > Pages
2. Under "Custom domain", enter: `dyrakarmy.eu`
3. Click "Save"
4. Wait for DNS propagation (usually 5-10 minutes)

### Verification

After DNS propagation:
1. Visit `https://dyrakarmy.eu`
2. Visit `https://www.dyrakarmy.eu`
3. Both should redirect to your GitHub Pages site

### Troubleshooting

If the site doesn't load:
1. Check DNS propagation status at https://dnschecker.org
2. Verify CNAME record in GitHub repository settings
3. Wait up to 48 hours for full DNS propagation
4. Clear browser cache and try again
