using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Button : MonoBehaviour
{
	static public Dictionary<char, Button> Buttons = new Dictionary<char, Button>();

	TextMesh text;

	[HideInInspector]
	public Button North, South, East, West;
	public float distance = 2;

	void Awake()
	{
		text = GetComponentInChildren<TextMesh> ();
		Buttons.Add (text.text[0], this);
		RaycastHit info;
		Debug.DrawRay (transform.position, transform.forward, Color.green, 10);
		Physics.Raycast (new Ray (transform.position, transform.forward), out info, distance);
		if (info.collider)
			East = info.collider.gameObject.GetComponent<Button> ();
		Physics.Raycast (new Ray (transform.position, -transform.forward), out info, distance);
		if (info.collider)
			West = info.collider.gameObject.GetComponent<Button> ();
		Physics.Raycast (new Ray (transform.position, transform.up), out info, distance);
		if (info.collider)
			North = info.collider.gameObject.GetComponent<Button> ();
		Physics.Raycast (new Ray (transform.position, -transform.up), out info, distance);
		if (info.collider)
			South = info.collider.gameObject.GetComponent<Button> ();
		Debug.Log (gameObject.name + ": N(" + (North ? North.name : "None") + ") E(" + (East ? East.name : "None") + ") S(" + (South ? South.name : "None") + ") W(" + (West ? West.name : "None") + ")");
	}

	void OnCollisionEnter(Collision other)
	{
		LevelManager.instance.passCodeText.text += text.text;	
	}
}
