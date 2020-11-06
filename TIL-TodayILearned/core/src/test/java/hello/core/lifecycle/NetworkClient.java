package hello.core.lifecycle;

public class NetworkClient {

    private String url;

    public NetworkClient() {
        System.out.println("Constructor call, url = " + url);
        connect();
        call("Initialization connection message");
    }

    public void setUrl(String url) {
        this.url = url;
    }
//    Called at service startup
    public void connect() {
        System.out.println("connect: = " + url);
    }

    public void call(String message) {
        System.out.println("call: " + url + " message = " + message);
    }

    //    Called at service termination
    public void disconnect() {
        System.out.println("close: " + url);
    }
}
