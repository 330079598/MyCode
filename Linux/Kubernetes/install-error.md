[toc]

---

---

---

安装`kubernetes`集群中遇到的问题

### 安装`dashboard`遇到的问题

#### 启动时pods 的 status一直是`CrashLoopBackOff`

1. 查看pods的状态：`watch -n 1  kubectl get pod -A`
2. 查看启动日志：` kubectl logs kubernetes-dashboard-58d9fffd68-wq9c2 -n kubernetes-dashboard --tail 50`
   - 使用方法：`kubectl logs podsName -n 命名空间 --tail 50`
   - 问题：

```bash
2022/05/08 21:43:45 Initializing csrf token from kubernetes-dashboard-csrf secret
panic: Get "https://10.96.0.1:443/api/v1/namespaces/kubernetes-dashboard/secrets/kubernetes-dashboard-csrf": dial tcp 10.96.0.1:443: i/o timeout
 
goroutine 1 [running]:
github.com/kubernetes/dashboard/src/app/backend/client/csrf.(*csrfTokenManager).init(0xc0002d99a0)
        /home/runner/work/dashboard/dashboard/src/app/backend/client/csrf/manager.go:41 +0x413
```

3. 解决方法：在273行添加一行内容`nodeName: k8s-master`（这个是你主节点的名称）

![dashboard](/images/dashboard.png)

4. 删除 dashboard 重新安装即可

   ```bash
   // 查询pod 
   kubectl get pods --all-namespaces | grep "dashboard"
   // 删除pod
   kubectl delete deployment kubernetes-dashboard  --namespace=kubernetes-dashboard
   kubectl delete deployment dashboard-metrics-scraper --namespace=kubernetes-dashboard
   
   // 查询service
   
   kubectl get service -A
   // 删除service
   kubectl delete service kubernetes-dashboard  --namespace=kubernetes-dashboard
   kubectl delete service dashboard-metrics-scraper  --namespace=kubernetes-dashboard
   // 删除账户和密钥
   kubectl delete sa kubernetes-dashboard --namespace=kubernetes-dashboard
   kubectl delete secret kubernetes-dashboard-certs --namespace=kubernetes-dashboard
   kubectl delete secret kubernetes-dashboard-key-holder --namespace=kubernetes-dashboard
   ```

   

   